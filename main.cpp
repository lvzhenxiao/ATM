#include"iostream"//����cout cin�����������������
#include<stdlib.h>//��̬�ڴ���ص�malloc�Ⱥ���
#include<iomanip>//�������Ϊ20�ַ�
#include<string.h>//���涨����ǹ����ַ���������һЩ��������

using namespace std;

class Bank//����һ����
{
public:
	Bank():cardID(123),psw(123),money(100),money2(100)
	{char name[20]="..";};                    //Ĭ�Ϲ��캯��,����ʼ��
	void UserLogin();                                  //�û���¼����
	void Menus();
	void Contact();                                      //�û�������������
    void SaveMoney();                                  //��������
    void TakeMoney();                                  //ȡ�������
    void Inquiry();                                    //��ѯ��������
    void Transfer();                                   //ת�˺�������
    void Changepsw();                                  //�޸����뺯������
private:
    char name[20];//�û�����
    long cardID;//�û�����
    long psw;//�û�����
    int money;//�û����
    int money2;
};
int num;
int ID2;

//***********************��¼**************************

void Bank::UserLogin()                                       //�û���¼��������
{
long ID;//longΪ�����ͱ���
long psw1;
cout<<"�û���¼:"<<endl;//ID�������ʱ������n���ַ���������
cout<<"���������Ŀ���:"<<endl;
cin>>ID;
cout<<"��������������:"<<endl;
cin>>psw1;
 if(ID==cardID &&psw1==psw)
{
 Menus();
}
 else
{
 cout<<"���Ŀ��Ż����������,����������!"<<endl;
 cout<<"���������Ŀ���:"<<endl;
 cin>>ID;
 cout<<"������������������:"<<endl;
 cin>>psw1;
 }
 if(ID==cardID &&psw1==psw)
{
 Menus();
}
else
{
 cout<<"��ܰ��ʾ��������󣬿��ѱ��Ե�(��ӡ��ƾ�������Ŀ��Ѿ���ͣһ��ҵ��):"<<endl;
 exit(1);
}
}

//******************************��������***********************************

void Bank::Menus()//�û�������������
{
int a;
do{
cout<<"1.���                 2.ȡ��\n";
cout<<"3.��ѯ���             4.�޸�����\n";
cout<<"5.ת��                 6.�˳�ϵͳ\n";
cout<<"��������Ҫ����ҵ�����ţ�";
cin>>a;
switch(a)
{
case 1:
SaveMoney();break;                                       //���
case 2:
TakeMoney();break;                                       //ȡ��
case 3:
Inquiry();break;                                         //��ѯ���
case 4:
Changepsw();break;                                       //�޸�����
case 5:
Transfer();break;                                        //ת��
case 6:
	exit(0);break;                                       //�˳�
default:{cout<<"�����������,������1-7֮�������!\n";}
}
}
while(1);
}

//*******************************����*******************************

void Bank::Contact()                                 //������������
{num++;
cout<<"��ӭע��:"<<endl;
cout<<"��������������:"<<endl;
cin>>name;
cout<<"���������Ŀ���:"<<endl;                           //cout<<"���������Ŀ���:"<<endl;
cin>>cardID;
cout<<"��������������:"<<endl;
cin>>psw;
cout<<"����������Ԥ����:"<<endl;
cin>>money;
cout<<"��ϲ��,�����ɹ�!"<<endl;
}
//*****************************���*******************************
void Bank::SaveMoney()                                 //��������
 {int money1;
cout<<"��ӭ��ʹ��ȡ��ҵ��"<<endl;
 cout<<"���������Ĵ����:"<<endl;
 cin>>money1;
 money=money+money1;
 cout<<"���ɹ����������Ϊ:"<<money<<endl;
}

//*****************************ȡ��*******************************

void Bank::TakeMoney()                                       //ȡ�������
{
int money1;
cout<<"��ӭ��ʹ��ȡ��ҵ��\n";
cout<<"ÿ��ȡ��ܳ���10000Ԫ"<<endl;
cout<<"��������ȡ��Ľ��:"<<endl;
cin>>money1;
if(money1>10000)
{
 cout<<"ÿ��ȡ��ܳ���10000Ԫ"<<endl;
 cout<<"ȡ������˻�������������ȡ����:";
 cin>>money1;
}
if(money>=money1)
{
 money=money-money1;
 cout<<"ȡ��ɹ�,���������Ϊ:"<<money<<endl;
}
else
 {
cout<<"ȡ������˻�������������ȡ����:";
cin>>money1;
money=money-money1;
cout<<"ȡ��ɹ�,���������Ϊ:"<<money<<endl;
}
}
void Bank::Inquiry()                                              //��ѯ��������
{
cout<<"��ӭ���в�ѯ���ҵ��\n";
cout<<"�������Ϊ:"<<money<<endl;
}

//**********************************ת��********************************

void Bank::Transfer()                                               //ת�˺�������
{
long ID2;
int money1;
int money2=100;
cout<<"��ӭʹ��ת��ҵ��\n"<<endl;
cout<<"ÿ��ת�˲��ܳ���10000Ԫ"<<endl;
cout<<"��������Ҫת�˵Ŀ���:"<<endl;
cin>>ID2;
if(ID2==001)
{
  cout<<"��������Ҫת�˵Ľ��:"<<endl;
  cin>>money1;
    if(money1>10000)
    {
     cout<<"ÿ��ȡ��ܳ���10000Ԫ"<<endl;
     cout<<"ȡ������˻�������������ȡ����:";
     cin>>money1;
    }
    if(money>=money1)
    {
    money=money-money1;
    cout<<"ת�˳ɹ�,���������Ϊ:"<<money<<endl;
    money2=money2+money1;
    cout<<"��ת�ʿ����Ϊ��"<<money2<<endl;
    }
    else
    {
    cout<<"�����˻�������������ȡ����:";
    cin>>money1;
    money=money-money1;
    money2=money2+money1;
    cout<<"ת�˳ɹ�,���������Ϊ:"<<money<<endl;
    cout<<"��ת�����Ϊ:"<<money2<<endl;
    }
}
else
cout<<"�˻�Ϊ�գ�����������"<<endl;
}

//***************************����*****************************

void Bank::Changepsw()                                                         //�޸����뺯������
{
long ID;
long psw1;
long psw2;
cout<<"��ӭʹ���޸�����ҵ��\n"<<endl;
cout<<"���������Ŀ��ţ�"<<endl;
cin>>ID;
cout<<"�������������룺"<<endl;
cin>>psw1;
if(ID==cardID && psw1==psw)
{
cout<<"����������ԭʼ���룺"<<endl;
cin>>psw1;
cout<<"���������������룺"<<endl;
cin>>psw2;
cout<<"ȷ�������룺����������������:"<<endl;
cin>>psw2;
psw=psw2;
cout<<"�޸�����ɹ�!"<<endl;
}
 else
{
cout<<"���Ŀ��Ż����������!"<<endl;
cout<<"��������������ԭʼ���룺"<<endl;
cin>>psw1;
if(psw1==psw)
{
cout<<"���������������룺"<<endl;
cin>>psw2;
cout<<"ȷ�������룺������������:"<<endl;
cin>>psw2;
psw=psw2;
cout<<"�޸�����ɹ�!"<<endl;
}
else
{
cout<<"��ܰ��ʾ:�������,���ѱ�����,��ȥ�˹�����̨�ⶳ."<<endl;
exit(1);
}
}
}

//*******************************������************************************

int main()
{
int i;
Bank k;
do
{
cout<<"                              ****************************************************************\n";
cout<<"                              *********************��ӭ���밢��Ͱ�����***********************"<<endl;
cout<<"                              *********************��ѡ����Ҫ���������:**********************\n";
cout<<"                              *                        1.ע��                                *\n";
cout<<"                              *                        2.�û���¼                            *"<<endl;
cout<<"                              *                        3.�˳�ϵͳ                            *"<<endl;
cout<<"                              *********************��������Ҫ����ҵ������:******************\n";
cout<<"                              ****************************************************************\n";
cin>>i;
if(i==3)
break;
switch(i)
{
case 1:
k.Contact();break;                                   //������������
case 2:
k.UserLogin();break;                                     //�û���¼
default:{cout<<"�����������,������1-3��ѡ��:\n";}
}
}
while(1);
}
