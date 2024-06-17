#include "station.h"
#include <string>
#include <QDebug>

//创建车站类数组，用于存放车站
Station stationArray[totalStationNumber];

Station::Station(QObject *parent)
    : QObject{parent}
{


}
Station::Station(std::string name,int m_LineNumber[3]){
    this->m_Name = name;
    this->m_LineNumber[0] = m_LineNumber[0];
    this->m_LineNumber[1] = m_LineNumber[1];
    this->m_LineNumber[2] = m_LineNumber[2];
}

bool stationExist(std::string station1,std::string station2){
    bool exist1 = false;
    bool exist2 = false;
    if(station1 == ""){
        exist1 = true;
    }
    else{
        for(int i=0;i<=192;i++){
            if(station1 == stationArray[i].m_Name){
                exist1= true;
            }
        }
    }
    if(station2==""){
        exist2=true;
    }
    else{
        for(int i=0;i<=192;i++){
            if(station2 == stationArray[i].m_Name){
                exist2 = true;
            }
        }
    }
    return exist1&&exist2;
}
bool stationIdentical(std::string station1,std::string station2){
    if(station1== station2){
        return true;
    }
    else{
        return false;
    }
}

int findStation(std::string stationName){
    if(stationName != ""){
        for(int i = 0;i <= 192;i++){
            if(stationName == stationArray[i].m_Name){
                return i;
            }
        }
    }
    return -1;//根据routeplan.cpp中的设置，此路径永不会执行
}

//使用弗洛伊德(Floyd)算法求任意两站的最短路径
int Distance[193][193];//距离矩阵
int Path[193][193];//路径矩阵

void setDistance01(){
    for(int i = 0;i < 193;i++){
        for(int j = 0;j < 193;j++){
            if(i != j){
                Distance[i][j] = 200;//不同站之间距离设为200（象征着无穷，不能设为INT_MAX，因为INT_MAX+1会溢出）
            }
            else{
                Distance[i][j] = 0;//相同站之间距离设为0
            }
        }
    }
    for(int i=0;i<=26;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;//相邻站距离设为1，注意Distance矩阵为对称矩阵
    }
    for(int i=28;i<=32;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[33][8]=Distance[8][33]=1;
    Distance[8][34]=Distance[34][8]=1;
    for(int i=34;i<=45;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    for(int i=47;i<=55;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[56][37]=Distance[37][56]=1;
    Distance[37][57]=Distance[57][37]=1;
    for(int i=57;i<=57;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[58][12]=Distance[12][58]=1;
    Distance[12][59]=Distance[59][12]=1;
    for(int i=59;i<=69;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    for(int i=71;i<=82;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[83][35]=Distance[35][83]=1;
    for(int i=84;i<=89;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[90][52]=Distance[52][90]=1;
    Distance[52][91]=Distance[91][52]=1;
    for(int i=91;i<=95;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[96][40]=Distance[40][96]=1;
    Distance[40][79]=Distance[79][40]=1;
    Distance[79][97]=Distance[97][79]=1;
    for(int i=97;i<=97;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[98][14]=Distance[14][98]=1;
    Distance[14][99]=Distance[99][14]=1;
    for(int i=99;i<=106;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    for(int i=108;i<=111;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[112][94]=Distance[94][112]=1;
    Distance[94][113]=Distance[113][94]=1;
    for(int i=113;i<=113;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[114][54]=Distance[54][114]=1;
    Distance[54][115]=Distance[115][54]=1;
    for(int i=115;i<=117;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[118][6]=Distance[6][118]=1;
    Distance[6][119]=Distance[119][6]=1;
    for(int i=119;i<=119;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[120][32]=Distance[32][120]=1;
    Distance[32][121]=Distance[121][32]=1;
    for(int i=121;i<=123;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[124][63]=Distance[63][124]=1;
    Distance[63][125]=Distance[125][63]=1;
    for(int i=125;i<=126;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[127][102]=Distance[102][127]=1;
    Distance[100][128]=Distance[128][100]=1;
    for(int i=128;i<=137;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    for(int i=139;i<=145;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[146][138]=Distance[138][146]=1;
    Distance[37][147]=Distance[147][37]=1;
    for(int i=147;i<=147;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[148][98]=Distance[98][148]=1;
    Distance[98][149]=Distance[149][98]=1;
    for(int i=149;i<=164;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[42][166]=Distance[166][42]=1;
    for(int i=166;i<=167;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[168][76]=Distance[76][168]=1;
    Distance[76][169]=Distance[169][76]=1;
    for(int i=169;i<=172;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[173][20]=Distance[20][173]=1;
    Distance[20][174]=Distance[174][20]=1;
    for(int i=174;i<=179;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[180][105]=Distance[105][180]=1;
    Distance[105][181]=Distance[181][105]=1;
    for(int i=181;i<=181;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    for(int i=183;i<=188;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
    Distance[189][172]=Distance[172][189]=1;
    Distance[172][190]=Distance[190][172]=1;
    for(int i=190;i<=191;i++){
        Distance[i][i+1]=Distance[i+1][i]=1;
    }
}
void setDistance02(){
    Distance[58][82]=Distance[82][58]=0;//
    Distance[13][81]=Distance[81][13]=0;
    Distance[132][178]=Distance[178][132]=0;
    Distance[151][171]=Distance[171][151]=0;
    Distance[19][192]=Distance[192][19]=0;
}
void setPath(){
    for(int i = 0;i < 193;i++){
        for(int j = 0;j < 193;j++){
            Path[i][j] = -1;//初始将Path所有元素设为-1，表示无路径
            if(Distance[i][j] != 200){
                Path[i][j] = i;//若i到j距离不为无穷（即200），则更新Path[i][j]
            }
        }
    }
}

void updateDistancePath(){
    for(int k = 0;k < 193;k++){
        for(int i = 0;i < 193;i++){
            for(int j = 0;j < 193;j++){
                if(Distance[i][k] + Distance[k][j] < Distance[i][j]){
                    Distance[i][j] = Distance[i][k] + Distance[k][j];//比较取小并更新
                    Path[i][j] = k;
                }
            }
        }
    }//最外层为中间点k在循环，遍历出以k为中间点的路径并与直达路径作比较，而后更新Distance矩阵
    for(int i = 0;i < 193;i++){
        for(int j = 0;j < 193;j++){
            Path[i][j] = previousPoint(i,j);
        }
    }
}
int previousPoint(int m,int n){
    if(Path[m][n] == m){
        return m;
    }
    else{
        return previousPoint(Path[m][n],n);
    }
    return -1;//永不会执行此路径
}

int whichHepingluDeparture(int destinationStation){
    return Distance[58][destinationStation]<Distance[82][destinationStation]?58:82;
}
int whichHepingluDestination(int departureStation){
    return Distance[departureStation][58]<Distance[departureStation][82]?58:82;
}//其实以上两个函数可以合二为一，因为Distance[i][j]=Distance[j][i]

void fillRouteArray(int m, int n, int *p) {
    if(Path[m][n] != m){
        *p++ = n;
        routeArrayLength++;
        fillRouteArray(m, Path[m][n], p);
        return;
    }
    else{
        *p++ = n;
        routeArrayLength++;
        *p++ = m;
        routeArrayLength++;
        return;
    }
}

int *routeArray = new int[200];
int routeArrayLength = 0;
int *Query(int depatureStation, int destinationStation) {
    routeArrayLength = 0;//每次查询都要重新将设为0
    int *routeArrayEnd = routeArray;
    fillRouteArray(depatureStation, destinationStation, routeArrayEnd);
    return routeArray;//返回翻转后的路径的起始地址
}

int getLength(int m,int n){
    return Distance[m][n];
}
bool viaTianjinbinguan(int *p,int x){
    bool judge = false;
    for(int i = 0;i < x;i++){
        if(p[i] == 101){
            judge = true;
        }
    }
    return judge;
}
bool judgeTransfer(int m,int  n){
    bool judge = false;
    if(getLine(m,n) == -1){
        judge = true;
    }
    return judge;
}
int getLine(int m,int n){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if((stationArray[m].m_LineNumber[i] == stationArray[n].m_LineNumber[j])&&(stationArray[m].m_LineNumber[i] != 0)){
                return stationArray[m].m_LineNumber[i];
            }
        }
    }
    return -1;
}




