// 查缺补漏146 347 28
// 最近最少使用缓存
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
/*
class LRUCache
{
private:
    vector<tuple<int, int>> cache;
    unordered_map<int, int> key_time;

public:
    LRUCache(int capacity)
    {
        cache.reserve(capacity);
    }

    int get(int key)
    {
        int retvalue = -1;
        for (auto t : cache)
        {
            int tkey = std::get<0>(t);
            ++key_time[tkey];
            if (tkey == key)
            {
                key_time[tkey] = 0; // 重置时间
                retvalue = std::get<1>(t);
            }
        }
        return retvalue;
    }

    void put(int key, int value)
    {
        //遍历 找到 | 没找到
        //找到 修改
        //没找到 添加，内存未满|内存已满
        int maxtimekey = -1;
        int maxtime = 0;
        bool exit = false;
        int index = -1;
        for (auto& t : cache)
        {
            ++index;
            int tkey = std::get<0>(t);
            ++key_time[tkey];
            if(!exit && key_time[tkey] > maxtime){
                maxtime = max(maxtime,key_time[tkey]);
                maxtimekey = tkey;
            }
            if (!exit && tkey == key)
            {
                key_time[tkey] = 0;     // 重置时间
                std::get<1>(t) = value; // 改变值
                exit = true;
            }
        }
        if(!exit){
            auto t = make_tuple(key,value);
            if(cache.size() < 2){
                cache.push_back(t);
                key_time[key] = 0;
            }else{
                cache[index] = t;
                key_time.erase(maxtimekey);
                key_time[key] = 0;
            }
        }
    }
};
*/
/*
class LRUCache {
private:
    unordered_map<int,int> key_index;
    unordered_map<int,int> key_time;
    vector<int> cache;
    int maxsize;
public:
    LRUCache(int capacity) {
        cache.reserve(capacity);
        maxsize = capacity;
    }
    
    int get(int key) {
        int retvalue = -1;
        for (auto& [nkey, index] : key_index) {
            ++key_time[nkey];
            if(nkey == key){
                key_time[nkey] = 0;
                retvalue = cache[index];
            }
        }
        return retvalue;
    }
    
    void put(int key, int value) {
        //遍历 找到 | 没找到
        //找到 修改
        //没找到 添加，内存未满|内存已满
        int maxtimekey = -1;
        int maxtime = 0;
        bool exit = false;
        for (auto& [nkey,index] : key_index)
        {
            ++key_time[nkey];
            if(!exit && key_time[nkey] >= maxtime){
                maxtime = max(maxtime,key_time[nkey]);
                maxtimekey = nkey;
            }
            if (!exit && nkey == key)
            {
                key_time[nkey] = 0;   // 重置时间
                cache[key_index[nkey]] = value; // 改变值
                exit = true;
            }
        }
        if(!exit){
            if(cache.size() < maxsize){
                cache.push_back(value);
                key_index[key] = cache.size()-1;
                key_time[key] = 0;
            }else{
                int maxindex = key_index[maxtimekey];
                cache[maxindex] = value;
                key_index.erase(maxtimekey);
                key_time.erase(maxtimekey);
                key_index[key] = maxindex;
                key_time[key] = 0;
            }
        }
    }
};
*/
struct DLinkedNode{
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};
class LRUCache {
private:
    unordered_map<int,DLinkedNode*> cache;//哈希表提供查询
    DLinkedNode* head;//链表提供顺序
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            DLinkedNode* node = new DLinkedNode(key,value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if(size > capacity){
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }else{
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//前K个高频元素
class Solution {
private:
    void MergeSort(vector<int>& nums,vector<int>& ret,int begin,int end){
        if(begin >= end-1)
            return; 
        int mid = (begin + end)/2;
        MergeSort(nums,ret,begin,mid);
        MergeSort(nums,ret,mid,end);
        Merge(nums,ret,begin,mid,end);
    }
    void Merge(vector<int>& nums,vector<int>& ret,int begin,int mid,int end){
        vector<int> temp(end - begin);
        vector<int> rettemp(end - begin);
        int left = begin;
        int right = mid;
        int index = 0;
        while(left < mid && right < end){
            if(nums[left] > nums[right]){
                rettemp[index] = ret[left];
                temp[index++] = nums[left++];
            }else{
                rettemp[index] = ret[right];
                temp[index++] = nums[right++];
            }
        }
        while(left < mid){
            rettemp[index] = ret[left];
            temp[index++] = nums[left++];
        }
        while(right < end){
            rettemp[index] = ret[right];
            temp[index++] = nums[right++];
        }
        for(int i = 0;i < temp.size();i++){
            nums[begin + i] = temp[i];
            ret[begin + i] = rettemp[i];
        }
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequence;
        for(int i = 0;i < nums.size();i++){
            frequence[nums[i]]++;
        }
        vector<int> ret;
        ret.reserve(frequence.size());
        vector<int> fre;
        fre.reserve(frequence.size());
        //归并排序
        for(auto& [key ,frenum] :  frequence){
            ret.push_back(key);
            fre.push_back(frenum);
        }
        MergeSort(fre,ret,0,frequence.size());
        vector<int> kret(ret.begin(),ret.begin()+k);
        return kret;
    }
};
class Solution {
public:
    static bool cmp(pair<int,int>& m,pair<int,int> n){
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequences;
        for(auto& v:nums){
            frequences[v]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)>  q(cmp);
        for(auto& [num,count] : frequences){
            if(q.size() == k){
                if(q.top().second < count){
                    q.pop();
                    q.emplace(num,count);
                }
            }else{
                q.emplace(num,count);
            }
        }
        vector<int> ret;
        while(!q.empty()){
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};