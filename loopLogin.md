在 Linux 中，普通用户出现循环登录的问题通常是由以下几种情况引起的：

1. **磁盘空间不足**：检查 `/home` 目录所在的分区是否满了，尤其是 `/tmp` 或根分区。可以通过以下命令查看磁盘使用情况：
   ```bash
   df -h
   ```

2. **权限问题**：如果用户的主目录权限设置错误，可能会导致登录失败。可以通过以下命令检查用户主目录的权限：
   ```bash
   ls -ld /home/username
   ```
   应确保用户对其主目录拥有读写权限（通常是 755 或 700 权限），如有必要，可以通过以下命令更改：
   ```bash
   sudo chmod 755 /home/username
   sudo chown username:username /home/username
   ```

3. **`.Xauthority` 文件问题**：`~/.Xauthority` 文件可能会导致登录问题。可以尝试删除或重命名该文件，系统会自动重新生成：
   ```bash
   mv ~/.Xauthority ~/.Xauthority.backup(或者sudo chown user /home/user/.Xauthority)
   ```

4. **配置文件错误**：检查用户主目录下的 `.bashrc` 或 `.profile` 文件中是否有错误配置。如果配置文件有问题，可能会导致无法正确登录。你可以通过以下命令备份并重命名配置文件：
   ```bash
   mv ~/.bashrc ~/.bashrc.backup
   mv ~/.profile ~/.profile.backup
   ```

5. **PAM 模块配置错误**：PAM（Pluggable Authentication Modules）控制登录的认证过程。如果 PAM 配置文件（通常在 `/etc/pam.d/` 目录下）被错误修改，也会导致循环登录问题。可以查看 `/var/log/auth.log` 或 `/var/log/secure` 日志文件中的信息来诊断 PAM 是否有问题。

6. **Xorg 配置问题**：如果你使用的是图形界面，可能是 Xorg 的配置问题。你可以切换到 TTY（Ctrl+Alt+F1~F6）并检查 Xorg 的日志：
   ```bash
   cat /var/log/Xorg.0.log
   ```

`.Xauthority` 文件是一个**二进制文件**，通常不是直接由用户阅读或编辑的。它存储的是 X Window System 相关的**授权信息**，包括认证 cookie，允许用户访问和使用图形界面的 X 服务器。

该文件的主要作用是帮助 X 服务器区分哪些用户有权限连接到它。每次用户启动图形界面会话时，系统会读取或更新 `.Xauthority` 文件，以确保用户身份得到了认证。

尽管 `.Xauthority` 文件存储的是二进制数据，但你可以使用 `xauth` 命令来查看其内容，格式如下：
```bash
xauth list
```

此命令会显示 `.Xauthority` 文件中存储的认证信息。
