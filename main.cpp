#include <iostream> 
#include <stdio.h>   //for puts
#include <stdlib.h>  //for exit

#include "FTP.h" 

using namespace std; 

int main(int argc, char* argv[]) 
{ 
    //登录 
    CFTP ftpclient; 
 
    int err; 

    //连接远程服务器ip
    err = ftpclient.ftp_connect("192.168.0.102"); 
    if(err)
    { 
        puts("connect ftp server failed"); 
        exit(-1); 
    } 
    puts("connect ok"); 

    //登陆远程服务器，账户和密码
    err = ftpclient.ftp_login("jiangtengfei","*****"); 
    if(err)
    { 
        puts("login failed"); 
        exit(-1); 
    } 
    puts("login ok"); 

    //33.txt为本地文件， 11.txt为远程文件（远程目录为ftp登入的目录，一般为家目录）
    err = ftpclient.ftp_download("/home/hadoop/FtpDemo/33.txt","11.txt"); 
    if(err)
    { 
        puts("download failed"); 
        exit(-1); 
    } 
    puts("download ok"); 

    //44.txt 为本地文件， tmp为远程路径， 22.txt 为远程路径下的文件
    err = ftpclient.ftp_upload("/home/hadoop/FtpDemo/44.txt","/Users/jiangtengfei/jiangtf/tmp","22.txt");
    if(err)
    { 
        puts("upload failed"); 
        exit(-1); 
    }
    puts("upload ok"); 

    err = ftpclient.ftp_quit(); 
    if(err)
    { 
        puts("quit failed"); 
        exit(-1); 
    } 
    puts("you quit"); 

    return 0; 
} 
