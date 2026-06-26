# 命令:
- claude 启动claude
- claude --dangerously-skip-permissions 启动claude并在后续同意所有权限申请
- claude --continue 打开上次对话
- /init 生成claudecode markdown文件，claude的记忆系统,可添加约束,每次对话都会查看
- /exit 退出
- /resume 查看历史
- /context 查看上下文用量
- /compact压缩对话上下文
- /clear  清空历史对话
- /skills 查看可用Skills
- /agents 查看Agent状态
- /plugins 查看已安装插件
- /rewind 回滚到对应结点
- /effort 选择思考强度 
- shift + tab 选择模式
- ctrl + j 换行 
- ! 切换终端模式
- @ 选择文件夹中文件
# 模式
## 计划模式
讨论并确定计划
# claude机制
## CLAUDE.md
CLAUDE.md 文件，默认提示词

可以在其中编辑想要Claude默认遵守的规则

调用方式：对话时@CLAUDE.md,后续不用再@
## Skills
## Agents
## Plugins
