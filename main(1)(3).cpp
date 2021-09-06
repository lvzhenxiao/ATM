#include"iostream"//调用cout cin出入输出函数函数库
#include<stdlib.h>//动态内存相关的malloc等函数
#include<iomanip>//设置域宽为20字符
#include<string.h>//里面定义的是关于字符串操作的一些基本函数

using namespace std;

class Bank//定义一个类
{
public:
	Bank():cardID(123),psw(123),money(100),money2(100)
	{char name[20]="..";};                    //默认构造函数,并初始化
	void UserLogin();                                  //用户登录声明
	void Menus();
	void Contact();                                      //用户操作函数声明
    void SaveMoney();                                  //存款函数声明
    void TakeMoney();                                  //取款函数声明
    void Inquiry();                                    //查询函数声明
    void Transfer();                                   //转账函数声明
    void Changepsw();                                  //修改密码函数声明
private:
    char name[20];//用户名字
    long cardID;//用户卡号
    long psw;//用户密码
    int money;//用户金额
    int money2;
};
int num;
int ID2;

//***********************登录**************************

void Bank::UserLogin()                                       //用户登录函数定义
{
long ID;//long为长整型变量
long psw1;
cout<<"用户登录:"<<endl;//ID是在输出时分配了n个字符的输出宽度
cout<<"请输入您的卡号:"<<endl;
cin>>ID;
cout<<"请输入您的密码:"<<endl;
cin>>psw1;
 if(ID==cardID &&psw1==psw)
{
 Menus();
}
 else
{
 cout<<"您的卡号或者密码错误,请重新输入!"<<endl;
 cout<<"请输入您的卡号:"<<endl;
 cin>>ID;
 cout<<"请重新输入您的密码:"<<endl;
 cin>>psw1;
 }
 if(ID==cardID &&psw1==psw)
{
 Menus();
}
else
{
 cout<<"温馨提示：密码错误，卡已被吃掉(打印出凭条，您的卡已经暂停一切业务):"<<endl;
 exit(1);
}
}

//******************************操作界面***********************************

void Bank::Menus()//用户操作函数定义
{
int a;
do{
cout<<"1.存款                 2.取款\n";
cout<<"3.查询余额             4.修改密码\n";
cout<<"5.转账                 6.退出系统\n";
cout<<"请输入您要办理业务的序号：";
cin>>a;
switch(a)
{
case 1:
SaveMoney();break;                                       //存款
case 2:
TakeMoney();break;                                       //取款
case 3:
Inquiry();break;                                         //查询余额
case 4:
Changepsw();break;                                       //修改密码
case 5:
Transfer();break;                                        //转账
case 6:
	exit(0);break;                                       //退出
default:{cout<<"你的输入有误,请输入1-7之间的整数!\n";}
}
}
while(1);
}

//*******************************开户*******************************

void Bank::Contact()                                 //开户函数定义
{num++;
cout<<"欢迎注册:"<<endl;
cout<<"请输入您的姓名:"<<endl;
cin>>name;
cout<<"请输入您的卡号:"<<endl;                           //cout<<"请输入您的卡号:"<<endl;
cin>>cardID;
cout<<"请输入您的密码:"<<endl;
cin>>psw;
cout<<"请输入您的预存金额:"<<endl;
cin>>money;
cout<<"恭喜您,开户成功!"<<endl;
}
//*****************************存款*******************************
void Bank::SaveMoney()                                 //存款函数定义
 {int money1;
cout<<"欢迎您使用取款业务"<<endl;
 cout<<"请输入您的存款金额:"<<endl;
 cin>>money1;
 money=money+money1;
 cout<<"存款成功，卡上余额为:"<<money<<endl;
}

//*****************************取款*******************************

void Bank::TakeMoney()                                       //取款函数定义
{
int money1;
cout<<"欢迎您使用取款业务\n";
cout<<"每次取款不能超过10000元"<<endl;
cout<<"请输入您取款的金额:"<<endl;
cin>>money1;
if(money1>10000)
{
 cout<<"每次取款不能超过10000元"<<endl;
 cout<<"取款金额超出账户余额，请重新输入取款金额:";
 cin>>money1;
}
if(money>=money1)
{
 money=money-money1;
 cout<<"取款成功,您卡上余额为:"<<money<<endl;
}
else
 {
cout<<"取款金额超出账户余额，请重新输入取款金额:";
cin>>money1;
money=money-money1;
cout<<"取款成功,您卡上余额为:"<<money<<endl;
}
}
void Bank::Inquiry()                                              //查询余额函数定义
{
cout<<"欢迎进行查询余额业务\n";
cout<<"卡上余额为:"<<money<<endl;
}

//**********************************转账********************************

void Bank::Transfer()                                               //转账函数定义
{
long ID2;
int money1;
int money2=100;
cout<<"欢迎使用转账业务\n"<<endl;
cout<<"每次转账不能超过10000元"<<endl;
cout<<"请输入您要转账的卡号:"<<endl;
cin>>ID2;
if(ID2==001)
{
  cout<<"请输入您要转账的金额:"<<endl;
  cin>>money1;
    if(money1>10000)
    {
     cout<<"每次取款不能超过10000元"<<endl;
     cout<<"取款金额超出账户余额，请重新输入取款金额:";
     cin>>money1;
    }
    if(money>=money1)
    {
    money=money-money1;
    cout<<"转账成功,您卡上余额为:"<<money<<endl;
    money2=money2+money1;
    cout<<"被转帐卡余额为："<<money2<<endl;
    }
    else
    {
    cout<<"金额超出账户余额，请重新输入取款金额:";
    cin>>money1;
    money=money-money1;
    money2=money2+money1;
    cout<<"转账成功,您卡上余额为:"<<money<<endl;
    cout<<"被转帐余额为:"<<money2<<endl;
    }
}
else
cout<<"账户为空，请重新输入"<<endl;
}

//***************************改密*****************************

void Bank::Changepsw()                                                         //修改密码函数定义
{
long ID;
long psw1;
long psw2;
cout<<"欢迎使用修改密码业务\n"<<endl;
cout<<"请输入您的卡号："<<endl;
cin>>ID;
cout<<"请输入您的密码："<<endl;
cin>>psw1;
if(ID==cardID && psw1==psw)
{
cout<<"请输入您的原始密码："<<endl;
cin>>psw1;
cout<<"请输入您的新密码："<<endl;
cin>>psw2;
cout<<"确认新密码：请重新输入新密码:"<<endl;
cin>>psw2;
psw=psw2;
cout<<"修改密码成功!"<<endl;
}
 else
{
cout<<"您的卡号或者密码错误!"<<endl;
cout<<"请重新输入您的原始密码："<<endl;
cin>>psw1;
if(psw1==psw)
{
cout<<"请输入您的新密码："<<endl;
cin>>psw2;
cout<<"确认新密码：请输入新密码:"<<endl;
cin>>psw2;
psw=psw2;
cout<<"修改密码成功!"<<endl;
}
else
{
cout<<"温馨提示:密码错误,卡已被冻结,请去人工服务台解冻."<<endl;
exit(1);
}
}
}

//*******************************主函数************************************

int main()
{
int i;
Bank k;
do
{
cout<<"                              ****************************************************************\n";
cout<<"                              *********************欢迎进入阿里巴巴银行***********************"<<endl;
cout<<"                              *********************请选择您要办理的手续:**********************\n";
cout<<"                              *                        1.注册                                *\n";
cout<<"                              *                        2.用户登录                            *"<<endl;
cout<<"                              *                        3.退出系统                            *"<<endl;
cout<<"                              *********************请输入您要办理业务的序号:******************\n";
cout<<"                              ****************************************************************\n";
cin>>i;
if(i==3)
break;
switch(i)
{
case 1:
k.Contact();break;                                   //开户函数调用
case 2:
k.UserLogin();break;                                     //用户登录
default:{cout<<"你的输入有误,请输入1-3的选择:\n";}
}
}
while(1);
}
