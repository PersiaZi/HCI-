#ifndef STATION_H
#define STATION_H
#include <QObject>
#include <QString>

class Station : public QObject
{
    Q_OBJECT
public:
    explicit Station(QObject *parent = nullptr);

    std::string m_Name;//站名
    int m_LineNumber[3];//站的线路，用0代表空缺，可暂且设置为换乘站最多3条线

    Station(std::string,int*);//Station类构造函数

    //重载运算符“=”
    void operator = (Station &s){
        this->m_Name=s.m_Name;
        this->m_LineNumber[0]=s.m_LineNumber[0];
        this->m_LineNumber[1]=s.m_LineNumber[1];
        this->m_LineNumber[2]=s.m_LineNumber[2];
    }
signals:
};

void setDistance01();//非出站换乘/虚拟换乘车站设置距离
void setDistance02();//出站换乘/虚拟换乘车站设置距离
void setPath();//设置路径矩阵
bool stationExist(std::string,std::string);//判断站名是否存在
bool stationIdentical(std::string,std::string);//判断出发车站和到达车站是否相同
extern Station stationArray[];//声明车站类数组，用于存放车站
const int totalStationNumber = 300;
int findStation(std::string);//查找车站并返回车站号码
void updateDistance();
void updateDistancePath();//更新Distance和Path矩阵
int previousPoint(int,int);//求路径前一个点
int whichHepingluDeparture(int);//为出发车站时，判断从3号线进还是4号线进
int whichHepingluDestination(int);//为到达车站时，判断从3号线出还是4号线出
void fillRouteArray(int,int,int*);//填充路径到routeArray中，注意Path是从目的地回溯到出发地
int* Query(int,int);//最短路径规划
int getLength(int,int);//获得路径长度
extern int routeArrayLength;//routeArray的长度
bool viaTianjinbinguan(int*,int);//判断是否
bool judgeTransfer(int,int);//判断是否换乘（包括虚拟换乘），两个参数对应的站中间必须相隔1个站
int getLine(int,int);//从相邻两车站获取线路



#endif // STATION_H
