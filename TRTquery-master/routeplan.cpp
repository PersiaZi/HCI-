#include "routeplan.h"
#include "station.h"
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QCheckBox>
#include <QMessageBox>
#include <QCompleter>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <Qprocess>
#include <QDir>

RoutePlan::RoutePlan(QWidget *parent)
    : QMainWindow{parent}
{
    QPixmap headPicture(":/new/prefix1/resource/ReferenceOnly.png");
    QLabel *head = new QLabel(this);
    head->setFixedSize(headPicture.size());
    head->setPixmap(headPicture);

    //设置输入界面
    QLabel *depatureLable = new QLabel("出发车站：",this);
    depatureLable->move(50,100);
    QLineEdit *depatureEdit = new QLineEdit(this);
    depatureEdit->move(110,100);
    QLabel *destinationLable = new QLabel("到达车站：",this);
    destinationLable->move(270,100);
    QLineEdit *destinationEdit = new QLineEdit(this);
    destinationEdit->move(330,100);
    QCheckBox*checkBox = new QCheckBox("出站换乘/虚拟换乘",this);
    checkBox->move(50,150);
    checkBox->setFixedWidth(135);
    checkBox->setTristate(false);
    QPushButton*startQuery = new QPushButton("查询",this);
    startQuery->move(500,100);

    //输入列表
    QStringList wordList;
    wordList<< "富锦路"<<"友谊西路"<<"宝安公路"<<"共富新村"<<"呼兰路"<<"通河新村"<<"共康路"<<"彭浦新村"<<"汶水路"<<"上海马戏城"<<"延长路"<<"中山北路"<<"上海火车站"<<"汉中路"<<"新闸路"<<"人民广场"<<"黄陂南路"<<"陕西南路"<<"常熟路"<<"衡山路"<<"徐家汇"<<"上海体育光"<<"漕宝路"<<"上海南站"<<"锦江乐园"<<"莲花路"<<"外环路"<<"莘庄"
             <<"徐泾东"<<"虹桥火车站"<<"虹桥2号航站楼"<<"淞虹路"<<"北新泾"<<"威宁路"<<"娄山关路"<<"中山公园"<<"江苏路"<<"静安寺"<<"南京西路"<<"陆家嘴"<<"东昌路"<<"世纪大道"<<"上海科技馆"<<"世纪公园"<<"龙阳路"<<"张江高科"<<"金科路"<<"广兰路"<<"唐镇"<<"创新中路"<<"华夏东路"<<"川沙路"<<"凌空路"<<"远东大道"<<"海天三路"<<"浦东国际机场"
             <<"上海南站"<<"石龙路"<<"龙漕路"<<"漕溪路"<<"宜山路"<<"虹桥路"<<"延安西路"<<"中山公园"<<"金沙江路"<<"曹杨路"<<"镇坪路"<<"中潭路"<<"上海火车站"<<"宝山路"<<"东宝兴路"<<"虹口足球场"<<"赤峰路"<<"大柏树"<<"江湾镇"<<"殷高西路"<<"长江南路"<<"淞发路"<<"张华浜"<<"淞滨路"<<"水产路"<<"宝杨路"<<"友谊路"<<"铁力路"<<"江杨北路"
             <<"宜山路"<<"虹桥路"<<"延安西路"<<"金沙江路"<<"曹杨路"<<"镇坪路"<<"中潭路"<<"上海火车站"<<"宝山路"<<"海伦路"<<"临平路"<<"大连路"<<"杨树浦路"<<"浦东大道"<<"世纪大道"<<"浦电路"<<"蓝村路"<<"塘桥"<<"南浦大道"<<"西藏南路"<<"鲁班路"<<"大木桥路"<<"东安路"<<"上海体育场"<<"上海体育馆"
             <<"莘庄"<<"春申路"<<"银都路"<<"颛桥"<<"北桥"<<"剑川路"<<"东川路"<<"西渡"<<"萧塘"<<"奉浦大道"<<"环城东路"<<"望园路"<<"金海湖"<<"奉贤新城"
             <<"港城路"<<"外高桥保税区北"<<"航津路"<<"外高桥保税区南"<<"洲海路"<<"五洲大道"<<"东靖路"<<"巨峰路"<<"五莲路"<<"巨峰路"<<"五莲路"<<"博兴路"<<"金桥路"<<"云山路"<<"德平路"<<"北洋泾路"<<"民生路"<<"源深体育中心"<<"世纪大道"<<"浦电路"<<"蓝村路"<<"上海儿童医学中心"<<"临沂新村"<<"高科西路"<<"东明路"<<"高青路"<<"华夏西路"<<"上南路"<<"灵岩南路"<<"东方体育中心"
             <<"花木路"<<"龙阳路"<<"芳华路"<<"锦绣路"<<"杨高南路"<<"高科西路"<<"云台路"<<"耀华路"<<"长清路"<<"后滩"<<"龙华中路"<<"东安路"<<"肇嘉浜路"<<"常熟路"<<"静安寺"<<"昌平路"<<"长寿路"<<"镇坪路"<<"岚皋路"<<"新村路"<<"大华三路"<<"行知路"<<"大场镇"<<"场中路"<<"上大路"<<"南陈路"<<"上海大学"<<"祁华路"<<"顾村公园"<<"刘行"<<"潘广路"<<"罗南新村"<<"美兰湖"
             <<"沈杜公路"<<"联航路"<<"江月路"<<"浦江镇"<<"芦恒路"<<"凌兆新村"<<"东方体育中心"<<"杨思"<<"成山路"<<"耀华路"<<"中华艺术宫"<<"西藏南路"<<"陆家浜路"<<"老西门"<<"大世界"<<"人民广场"<<"曲阜路"<<"中兴路"<<"西藏北路"<<"虹口足球场"<<"曲阳路"<<"四平路"<<"鞍山新村"<<"江浦路"<<"黄兴路"<<"延吉中路"<<"黄兴公园"<<"翔殷路"<<"嫩江路"<<"市光路"
             <<"曹路"<<"民雷路"<<"顾唐路"<<"金海路"<<"金吉路"<<"金桥"<<"台儿庄路"<<"蓝天路"<<"芳甸路"<<"杨高中路"<<"世纪大道"<<"商城路"<<"小南门"<<"陆家浜路"<<"马当路"<<"打浦桥"<<"嘉善路"<<"肇嘉浜路"<<"徐家汇"<<"宜山路"<<"桂林路"<<"漕河泾开发区"<<"合川路"<<"星中路"<<"七宝"<<"中春路"<<"九亭"<<"泗泾"<<"佘山"<<"洞泾"<<"松江大学城"<<"松江新城"<<"松江体育中心"<<"醉白池"<<"松江南站"
             <<"基隆路"<<"港城路"<<"高桥"<<"高桥西"<<"双江路"<<"国帆路"<<"新江湾城"<<"殷高东路"<<"三门路"<<"江湾体育场"<<"五角场"<<"国权路"<<"同济大学"<<"四平路"<<"邮电新村"<<"海伦路"<<"四川北路"<<"天潼路"<<"南京东路"<<"豫园"<<"老西门"<<"新天地"<<"陕西南路"<<"上海图书馆"<<"交通大学"<<"虹桥路"<<"宋园路"<<"伊犁路"<<"水城路"<<"龙溪路"<<"上海动物园"<<"虹桥1号航站楼"<<"虹桥2号航站楼"<<"虹桥火车站"
             <<"迪士尼"<<"康新公路"<<"秀沿路"<<"罗山路"<<"御桥"<<"浦三路"<<"三林东"<<"三林"<<"东方体育中心"<<"龙耀路"<<"云锦路"<<"龙华"<<"上海游泳馆"<<"徐家汇"<<"交通大学"<<"江苏路"<<"隆德路"<<"曹杨路"<<"枫桥路"<<"真如"<<"上海西站"<<"李子园"<<"祁连山路"<<"武威路"<<"桃浦新村"<<"南翔"<<"陈翔公路"<<"马陆"<<"嘉定新城"<<"白银路"<<"嘉定西"<<"嘉定北"
             <<"金海路"<<"申江路"<<"金京路"<<"杨高北路"<<"巨峰路"<<"东陆路"<<"复兴岛"<<"爱国路"<<"隆昌路"<<"宁国路"<<"江浦公园"<<"大连路"<<"提篮桥"<<"国际客运中心"<<"天潼路"<<"曲阜路"<<"汉中路"<<"南京西路"<<"陕西南路"<<"嘉善路"<<"大木桥路"<<"龙华中路"<<"龙华"<<"龙漕路"<<"漕宝路"<<"桂林公园"<<"虹漕路"<<"虹梅路"<<"东兰路"<<"顾戴路"<<"虹莘路"<<"七莘路"
             <<"金运路"<<"金沙江西路"<<"丰庄"<<"祁连山南路"<<"真北路"<<"大渡河路"<<"金沙江路"<<"隆德路"<<"武宁路"<<"长寿路"<<"江宁路"<<"汉中路"<<"自然博物馆"<<"南京西路"<<"淮海中路"<<"新天地"<<"马当路"<<"世博会博物馆"<<"世博大道"<<"长清路"<<"成山路"<<"东明路"<<"华鹏路"<<"下南路"<<"北蔡"<<"陈春路"<<"莲溪路"<<"华夏中路"<<"中科路"<<"学林路"<<"张江路"
             <<"封浜站"<<"乐秀路"<<"临洮路"<<"嘉怡路"<<"定边路"<<"真新新村"<<"真光路"<<"铜川路"<<"真如"<<"中宁路"<<"曹杨路"<<"武宁路"<<"武定路"<<"静安寺"<<"一大会址·黄陂南路"<<"大世界"<<"豫园"<<"陆家嘴"<<"浦东南路"<<"浦东大道"<<"源深路"<<"昌邑路"<<"歇浦路"<<"云山路"<<"蓝天路"<<"黄杨路"<<"云顺路"<<"浦东足球场"<<"金粤路"<<"桂桥路"
             <<"龙阳路"<<"华夏中路"<<"罗山路"<<"周浦东"<<"鹤沙航城"<<"航头东"<<"新场"<<"野生动物园"<<"惠南"<<"惠南东"<<"书院"<<"临港大道"<<"滴水湖"
             <<"虹桥火车站"<<"褚光路"<<"蟠龙路"<<"徐盈路"<<"徐泾北城"<<"嘉松中路"<<"赵巷"<<"汇金路"<<"青浦新城"<<"漕盈路"<<"淀山湖大道"<<"朱家角"<<"东方绿舟"
             <<"航头"<<"下沙"<<"鹤涛路"<<"沈梅路"<<"繁荣路"<<"周浦"<<"康桥"<<"御桥"<<"莲溪路"<<"北中路"<<"芳芯路"<<"龙阳路"<<"迎春路"<<"杨高中路"<<"民生路"<<"昌邑路"<<"丹阳路"<<"平凉路"<<"江浦公园"<<"江浦路"<<"抚顺路"<<"国权路"<<"复旦大学"<<"上海财经大学"<<"殷高路"<<"长江南路";
    QCompleter *completer = new QCompleter(wordList, this);
    depatureEdit->setCompleter(completer);
    destinationEdit->setCompleter(completer);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    //判断选择框状态
    connect(checkBox, &QCheckBox::stateChanged, this, &RoutePlan::onCheckBoxStateChanged);


    //设置输出与错误提示，注意函数参数从QString转换到std::string
    connect(startQuery, &QPushButton::clicked, this, [=]() {

            // 以下生成路径

                // 调用 Python 脚本获取 AI 路径
                QString startStation = depatureEdit->text();
                QString endStation = destinationEdit->text();
                QString apiKey = "914c8b1772c9e5922d189e12ac1a0833.FFy2wsbQHfl5EKMH";

                QProcess process;
                QString program = "python";
                QString scriptPath = QDir::currentPath() + "/ai.py"; // 获取绝对路径
                QStringList arguments;
                arguments << scriptPath << startStation << endStation << apiKey;

                qDebug() << "Executing:" << program << arguments;

                process.start(program, arguments);
                process.waitForFinished();

                QString output = process.readAllStandardOutput();
                QString errorOutput = process.readAllStandardError();

                if (!errorOutput.isEmpty()) {
                    qDebug() << "Error Output:" << errorOutput;
                }

                qDebug() << "Standard Output:" << output;

                // 显示 AI 返回的路径信息
                QLabel *routeLabel = new QLabel(this);
                routeLabel->setText(output);
                routeLabel->adjustSize();
                routeLabel->move(50, 200);
                routeLabel->show();


    });
}

//判断选择框状态函数
void RoutePlan::onCheckBoxStateChanged(int state) {
    if (state == Qt::Checked) {
        setDistance01();//▲注意
        setDistance02();
        setPath();//▲注意
        updateDistancePath();
    }
    else if (state == Qt::Unchecked) {
        setDistance01();
        setPath();//▲注意
        updateDistancePath();
    }
}
