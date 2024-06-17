#include "stationlist.h"
#include "station.h"
#include <QTabWidget>
#include <QLabel>
#include <QFormLayout>
#include <QIcon>

StationList::StationList(QWidget *parent)
    : QMainWindow{parent}
{
    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->setFixedSize(1129,800);

    //添加站名和换乘提示，注意从std::string转到QString，暂缓开通需额外添加

    //1号线站名列表
    QWidget *tab1 = new QWidget();
    QIcon L1(":/new/prefix1/resource/Line1.png");
    tabWidget->addTab(tab1, L1,"1号线");
    QFormLayout *formLayout1=new QFormLayout(tab1);
    QStringList stations = {
        "富锦路",
        "友谊西路",
        "宝安公路",
        "共富新村",
        "呼兰路",
        "通河新村",
        "共康路",
        "彭浦新村",
        "汶水路",
        "上海马戏城",
        "延长路",
        "中山北路",
        "上海火车站",
        "汉中路",
        "新闸路",
        "人民广场",
        "黄陂南路",
        "陕西南路",
        "常熟路",
        "衡山路",
        "徐家汇",
        "上海体育馆",
        "漕宝路",
        "上海南站",
        "锦江乐园",
        "莲花路",
        "外环路",
        "莘庄"
    };
    for (int i = 0; i < stations.size(); ++i) {
        QLabel *label = new QLabel(stations.at(i));
        formLayout1->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
    //2号线站名列表
    QWidget *tab2 = new QWidget();
    QIcon L2(":/new/prefix1/resource/Line2.png");
    tabWidget->addTab(tab2, L2,"2号线");
    QFormLayout *formLayout2=new QFormLayout(tab2);
    QStringList stations2 = {
        // 起点至虹桥火车站区间
        "徐泾东",
        "虹桥火车站",
        "虹桥2号航站楼",
        "淞虹路",
        "北新泾",
        "威宁路",
        "娄山关路",
        "中山公园",

        // 中山公园至世纪公园区间
        "江苏路",
        "静安寺",
        "南京西路",
        "人民广场",
        "南京东路",
        "陆家嘴",
        "东昌路",
        "世纪大道",
        "上海科技馆",
        "世纪公园",

        // 世纪公园至浦东国际机场区间
        "龙阳路",
        "张江高科",
        "金科路",
        "广兰路",
        "唐镇",
        "创新中路",
        "华夏东路",
        "川沙",
        "凌空路",
        "远东大道",
        "海天三路",
        "浦东国际机场"
    };
    for (int i = 0; i < stations2.size(); ++i) {
        QLabel *label = new QLabel(stations2.at(i));
        formLayout2->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }

    //3号线站名列表
    QWidget *tab3 = new QWidget();
    QIcon L3(":/new/prefix1/resource/Line3.png");
    tabWidget->addTab(tab3,L3, "3号线");
    QFormLayout *formLayout3=new QFormLayout(tab3);
    QStringList stations3 = {
        // 起始站至中山公园区间
        "上海南站",
        "石龙路",
        "龙漕路",
        "漕溪路",
        "宜山路",
        "虹桥路",
        "延安西路",
        "中山公园",

        // 中山公园至江湾镇区间
        "金沙江路",
        "曹杨路",
        "镇坪路",
        "中潭路",
        "上海火车站",
        "宝山路",
        "东宝兴路",
        "虹口足球场",
        "赤峰路",
        "大柏树",
        "江湾镇",

        // 江湾镇至终点站区间
        "殷高西路",
        "长江南路",
        "淞发路",
        "张华浜",
        "淞滨路",
        "水产路",
        "宝杨路",
        "友谊路",
        "铁力路",
        "江杨北路"
    };
    for (int i = 0; i < stations3.size(); ++i) {
        QLabel *label = new QLabel(stations3.at(i));
        formLayout3->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
    //4号线站名列表
    QWidget *tab4 = new QWidget();
    QIcon L4(":/new/prefix1/resource/Line4.png");
    tabWidget->addTab(tab4, L4, "4号线");
    QFormLayout *formLayout4=new QFormLayout(tab4);
    QStringList stations4 = {
        // 起始站至海伦路区间
        "宜山路",
        "虹桥路",
        "延安西路",
        "中山公园",
        "金沙江路",
        "曹杨路",
        "镇坪路",
        "中潭路",
        "上海火车站",
        "宝山路",
        "海伦路",

        // 海伦路至浦东大道区间
        "临平路",
        "大连路",
        "杨树浦路",
        "浦东大道",

        // 浦东大道至世纪大道区间（换乘站）
        "世纪大道", // 与地铁2、6、9号线换乘

        // 世纪大道至蓝村路区间
        "浦电路",
        "蓝村路",

        // 蓝村路至塘桥区间
        "塘桥",

        // 塘桥至南浦大桥区间
        "南浦大桥",

        // 南浦大桥至西藏南路区间
        "西藏南路", // 与地铁8号线换乘

        // 西藏南路至鲁班路区间
        "鲁班路",

        // 鲁班路至大木桥路区间
        "大木桥路",

        // 大木桥路至东安路区间
        "东安路", // 与地铁7号线换乘

        // 东安路至上海体育场区间
        "上海体育场",

        // 上海体育场至上海体育馆区间（换乘站）
        "上海体育馆", // 与地铁1、3、11号线换乘

        // 上海体育馆至宜山路区间（终点站，与起始站相同）
        "宜山路"
    };
    for (int i = 0; i < stations4.size(); ++i) {
        QLabel *label = new QLabel(stations4.at(i));
        formLayout4->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
    //5号线站名列表
    QWidget *tab5 = new QWidget();
    QIcon L5(":/new/prefix1/resource/Line5.png");
    tabWidget->addTab(tab5, L5, "5号线");
    QFormLayout *formLayout5=new QFormLayout(tab5);
    QStringList stations5 = {
        // 主线站点（莘庄-奉贤新城）
        "莘庄",
        "春申路",
        "银都路",
        "颛桥",
        "北桥",
        "剑川路",
        "东川路",
        "江川路",
        "西渡",
        "萧塘",
        "奉浦大道",
        "环城东路",
        "望园路",
        "金海湖",
        "奉贤新城",

        // 支线站点（东川路-闵行开发区，注意东川路与主线共用）
        // 注意这里不再添加"东川路"，因为它已经在主线站点中
        "金平路",
        "华宁路",
        "文井路",
        "闵行开发区"
    };
    for (int i = 0; i < stations5.size(); ++i) {
        QLabel *label = new QLabel(stations5.at(i));
        formLayout5->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
    //6号线站名列表
    QWidget *tab6 = new QWidget();
    QIcon L6(":/new/prefix1/resource/Line6.png");
    tabWidget->addTab(tab6, L6, "6号线");
    QFormLayout *formLayout6=new QFormLayout(tab6);

    QStringList stations6 = {
    "港城路",
    "外高桥保税区北",
    "航津路",
    "外高桥保税区南",
    "洲海路",
    "五洲大道",
    "东靖路",
    "巨峰路",
    "五莲路",
    "博兴路",
    "金桥路",
    "云山路",
    "德平路",
    "北洋泾路",
    "浦电路",
    "世纪大道", // 与地铁2、4、9号线换乘
    "蓝村路",
    "上海儿童医学中心",
    "临沂新村",
    "高科西路",
    "东明路",
    "高青路",
    "华夏西路",
    "上南路",
    "灵岩南路",
    "东方体育中心" // 与地铁8、11号线换乘
    };

    // 接下来可以使用stations6变量来访问和操作这些站点信息
    for (int i = 0; i < stations6.size(); ++i) {
        QLabel *label = new QLabel(stations6.at(i));
        formLayout6->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
    //8号线站名列表
    QWidget *tab7 = new QWidget();
    QIcon L8(":/new/prefix1/resource/Line8.png");
    tabWidget->addTab(tab7, L8, "8号线");
    QFormLayout *formLayout7=new QFormLayout(tab7);
    QStringList stations8 = {
        "市光路",
        "嫩江路",
        "翔殷路",
        "黄兴公园",
        "延吉中路",
        "黄兴路",
        "江浦路",
        "鞍山新村",
        "四平路",
        "曲阳路",
        "虹口足球场", // 与地铁3号线换乘
        "西藏北路",
        "中兴路",
        "曲阜路",
        "人民广场", // 与地铁1、2号线换乘
        "大世界",
        "老西门", // 与地铁10号线换乘
        "陆家浜路", // 与地铁9号线换乘
        "西藏南路", // 与地铁4号线换乘
        "中华艺术宫",
        "耀华路",
        "成山路",
        "杨思",
        "东方体育中心", // 与地铁6、11号线换乘
        "凌兆新村",
        "芦恒路",
        "浦江镇",
        "江月路",
        "联航路",
        "沈杜公路"
    };
    for (int i = 0; i < stations8.size(); ++i) {
        QLabel *label = new QLabel(stations8.at(i));
        formLayout7->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
    //9号线站名列表
    QWidget *tab8 = new QWidget();
    QIcon L9(":/new/prefix1/resource/Line9.png");
    tabWidget->addTab(tab8, L9, "9号线");
    QFormLayout *formLayout8=new QFormLayout(tab8);
    QStringList stations9 = {
        "松江南站",
        "醉白池",
        "松江体育中心",
        "松江大学城",
        "洞泾",
        "佘山",
        "泗泾",
        "九亭",
        "中春路",
        "七宝",
        "星中路",
        "合川路",
        "漕河泾开发区",
        "桂林路",
        "宜山路", // 与地铁3、4号线换乘
        "徐家汇", // 与地铁1号线换乘
        "肇嘉浜路", // 与地铁7号线换乘
        "嘉善路",
        "打浦桥",
        "马当路", // 与地铁13号线换乘
        "陆家浜路", // 与地铁8号线换乘
        "小南门",
        "商城路",
        "世纪大道", // 与地铁2、4、6号线换乘
        "杨高中路",
        "芳甸路",
        "蓝天路",
        "台儿庄路",
        "金桥",
        "金吉路",
        "金海路",
        "顾唐路",
        "曹路"
    };
    for (int i = 0; i < stations9.size(); ++i) {
        QLabel *label = new QLabel(stations9.at(i));
        formLayout8->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
    //10号线站名列表
    QWidget *tab9 = new QWidget();
    QIcon L10(":/new/prefix1/resource/Line10.png");
    tabWidget->addTab(tab9, L10, "10号线");
    QFormLayout *formLayout9=new QFormLayout(tab9);
    QStringList stations10 = {
        "基隆路",
        "港城路",
        "高桥",
        "高桥西",
        "双江路",
        "国帆路",
        "新江湾城",
        "殷高东路",
        "三门路",
        "江湾体育场",
        "五角场",
        "同济大学",
        "国权路",
        "邮电新村",
        "海伦路", // 与地铁4号线换乘
        "四川北路",
        "南京东路", // 与地铁2号线换乘
        "豫园",
        "老西门", // 与地铁8号线换乘
        "新天地",
        "交通大学",
        "陕西南路", // 与地铁1、12号线换乘
        "上海图书馆",
        "虹桥路", // 与地铁3、4号线换乘
        "宋园路",
        "伊犁路",
        "水城路",
        "龙溪路",
        "虹桥火车站", // 与地铁2、17号线换乘
        "虹桥2号航站楼",
        "虹桥1号航站楼",
        "航中路",
        "紫藤路",
        "龙柏新村",
        "爱博家园",
        "吴中路",
        "航南路",
        "虹桥路地铁站" // 与地铁3号线换乘
    };
    for (int i = 0; i < stations10.size(); ++i) {
        QLabel *label = new QLabel(stations10.at(i));
        formLayout9->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
    //11号线站名列表
    QWidget *tab10 = new QWidget();
    QIcon L11(":/new/prefix1/resource/Line11.png");
    tabWidget->addTab(tab10, L11, "11号线");
    QFormLayout *formLayout10=new QFormLayout(tab10);
    QStringList stations11 = {
        "迪士尼",
        "康新公路",
        "秀沿路",
        "罗山路",
        "御桥",
        "浦三路",
        "三林东",
        "三林",
        "东方体育中心", // 与地铁6、8号线换乘
        "龙华",
        "云锦路",
        "龙耀路",
        "上海游泳馆",
        "交通大学", // 与地铁10号线换乘
        "徐家汇", // 与地铁1、9号线换乘
        "上海体育馆",
        "漕溪路",
        "龙漕路",
        "龙华中路", // 与地铁7号线换乘
        "船厂路",
        "东安路",
        "交通大学", // 重复站点，与地铁10号线换乘
        "江苏路", // 与地铁2号线换乘
        "隆德路",
        "曹杨路", // 与地铁3、4号线换乘
        "枫桥路",
        "真如",
        "上海西站",
        "李子园",
        "祁连山路",
        "武威东路",
        "桃浦新村",
        "南翔",
        "马陆",
        "嘉定新城",
        "白银路",
        "嘉定西",
        "嘉定北"
    };
    for (int i = 0; i < stations11.size(); ++i) {
        QLabel *label = new QLabel(stations11.at(i));
        formLayout10->addRow(QString::number(i+1) + ".", label); // 使用站点索引作为标签
    }
}
