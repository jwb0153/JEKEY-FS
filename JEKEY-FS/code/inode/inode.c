#include<time.h>
#include<stdbool.h>
#define TOTAL_INODE 1024
#define INODE_TO_BLOCK 4
#define FILE_BLOCK_MAX_LENGTH 8

#define WRITE_ONLY 1
#define READ_ONLY 2
#define WRITE_AND_READ 3

struct inode
{
    unsigned short file_type;//fle type
    unsigned short protection;//write read write&read
    unsigned int user_id;   //文件所属用户到id
    unsigned short file_size;
    unsigned short disk_add[INODE_TO_BLOCK];

    time_t access_time;//last visit time
    time_t modification_time;//last change time
    time_t create_time;
};

void initInode();

void saveInode(struct inode *node){
    
}

void createDirentInode(struct inode *node, struct block *b,struct user *u){
node->user_id=u->user_id;
node->

}

void createFileInode(struct inode *node, struct block *b,struct user *u,unsigned long size,unsigned short protection);

bool setCreateTime(struct inode *node,time_t time)
{
   node->create_time=time;
}

bool setAccessTime(struct inode *node, time_t time){
    node->access_time=time;
}

bool setModificationTime(struct inode *node, time_t time){
    node->modification_time=time;
}

