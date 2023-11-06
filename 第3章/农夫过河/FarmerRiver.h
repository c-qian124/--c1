#ifndef FARMERRIVER_H
#define FARMERRIVER_H

//函数功能： 判断当前状态下农夫是否在右岸
//输入参数status： 当前状态
//返回值： 在右岸返回1，否则返回0
int FarmerOnRight(int status);   

//函数功能： 判断当前状态下狼是否在右岸
//输入参数status： 当前状态
//返回值： 在右岸返回1，否则返回0
int WorfOnRight(int status);      

//函数功能： 判断当前状态下白菜是否在右岸
//输入参数status： 当前状态
//返回值： 在右岸返回1，否则返回0
int CabbageOnRight(int status);   

//函数功能： 判断当前状态下羊是否在右岸
//输入参数status： 当前状态
//返回值： 在右岸返回1，否则返回0
int GoatOnRight(int status);    

//函数功能： 判断当前状态是否是安全的
//输入参数status： 当前状态
//返回值： 安全返回1，否则返回0
int IsSafe(int status);     

//函数功能： 农夫过河
//输入参数： 无
//返回值： 无
void FarmerRiver();

#endif