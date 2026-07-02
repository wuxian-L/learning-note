# 配置
- git config --global user.name "wuxian-L"
- git config --global user.email [邮箱]
- .gitignore文件 包含在其中的文件地址不会被git跟踪
# 基础操作
- git init 初始化
- git status 查看当前状态
- git add . 添加跟踪文件                      打包快递
- git commit 提交
- git commit -m "" 提交                      添加备注
- git commit -a -m "说明"  -a 相当于同时add和commit
- git commit -am "说明"
- git push

- git remote add origin [仓库链接]            添加地址
- git push origin master                     寄出快递

- git rm 从Git管理中删除文件/目录
- --cached 只操作Git的暂存区，不动工作区
- -r 递归处理 删除目录时必须加
- git rm -r --cached secret git删除暂存区secret/停止跟踪secret

- git log 查看先前版本
- echo "[文件内容]" > [文件名]
- touch .gitignore 添加.gitignore文件
    .gitignore配置文件 添加在其中的文件名不会被追踪提交

# 分支操作
- git branch [分支名] 创建分支
- git branch 查看项目分支状态
- git checkout [分支名] 切换到其他分支
- git checkout -b [分支名] 创建并切换到新分支 
- git branch -d/-D [分支名] 删除分支
- git merge [分支名] 合并分支 把别的分支合并到当前所处的分支上


- git clone [仓库链接] 克隆远程仓库到本地包含.git信息
- git remote -v 查看与本地仓库联系的远程仓库

    origin 表示远程仓库的名字
- git fetch 将远程仓库版本拉取到本地版本库,本地代码暂时不会改变
- git diff [远程仓库名]/[分支名]
- git pull 将远程仓库内容整合到本地工作区
