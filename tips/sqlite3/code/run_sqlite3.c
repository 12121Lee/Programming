#include <stdio.h>
#include <sqlite3.h>

// 回调函数，用于处理查询结果的每一行
/*
int callback(void *data, int argc, char **argv, char **col_names);
void *data: 用户自定义指针，来自 sqlite3_exec() 的第 3 个参数（通常用于传递上下文）
int argc: 当前行的列数（字段数量)
char **argv: 当前行各列的值（字符串数组），argv[i] 是第 i 列的值
char **col_names: 列名数组（与 argv 一一对应），col_names[i] 是第 i 列的列名
*/
static int callback(void *NotUsed, int argc, char **argv, char **azColName) 
{
    for (int i = 0; i < argc; ++i) 
    {
        printf("%-10s", argv[i] ? argv[i] : "NULL");
        if (i < argc - 1) 
            printf("|");
    }
    printf("\n");
    return 0;
}

int main() 
{
    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    // 打开数据库
    rc = sqlite3_open("test.db", &db);
    if(rc != SQLITE_OK) 
    {
        fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // 执行SQL查询
    const char *sql = "SELECT * FROM company;";
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
    if(rc != SQLITE_OK) 
    {
        fprintf(stderr, "SQL错误: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    // 关闭数据库
    sqlite3_close(db);
    return 0;
}