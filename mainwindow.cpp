#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QString"
#include<string>
#include"node.h"
#include"list.h"
#include"person.h"
#include<qDebug>

 List *pList= new List();

QString str2qstr(const string str)
{
    return QString::fromLocal8Bit(str.data());
}

string qstr2str(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return string(cdata);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{

    delete ui;
}



/**************************************
*在添加到通讯录中的数据查找相关信息如
* 输入姓名------>显示电话号码
* 输入电话号码------>显示姓名
***************************************/
void MainWindow::on_search_clicked()//输入姓名或者电话号码是显示另外一个信息
{

    Node *currentNode=new Node;    //创建新节点
    pList->GetElem(0,currentNode); //获取添加到通讯录中的首元素
    cout<<"1"<<currentNode->data.name; //测试获取的信息，在运行程序时 输入了要添加的数据后，进行相应的查找，
                                        //结果在应用程序输出栏没有显示，退出后又在应用输出栏打印了
    QString qs_Name = ui->name->text();
    QString qs_Phone = ui->phone->text();

    if(qs_Name.isEmpty() && qs_Phone.isEmpty())//还有这些条件好像进不去
    {
        //提示输入需要查找的信息
    }
     if((!qs_Name.isEmpty())&&(qs_Phone.isEmpty()))
    {
        //通过姓名查电话
        if(currentNode->data.name!= qstr2str(qs_Name))
        {
            currentNode=currentNode->next;
            cout<<currentNode->data;  //应用输出出没有改行信息

        }
        else
        {
            qs_Phone=str2qstr(currentNode->data.phone);
        }
    }
    if(qs_Name.isEmpty() && !qs_Phone.isEmpty())
    {
             //通过电话查姓名
        if(currentNode->data.phone!= qstr2str(qs_Phone))
        {
            currentNode=currentNode->next;

        }
        else
        {
            qs_Name=str2qstr(currentNode->data.name);
        }

    }
}

/***************************
*点击清除按钮后，将姓名和电话栏文本内容清空
*****************************/

void MainWindow::on_clear_clicked()
{
    ui->name->setText("");
    ui->phone->setText("");
}



/*********************************
 * 点击退出按钮，然后关闭主窗口
 ********************************/
void MainWindow::on_quit_clicked()
{
    this->close();
}


/*****************************
*点击添加按钮，添加通讯信息
*****************************/
void MainWindow::on_Add_pressed()//name 和phone为空时 需要处理
{
     Node node;

     node.data.name=qstr2str(ui->name->text());
     node.data.phone=qstr2str(ui->phone->text());
     pList->ListInsertHead(&node);


    pList->ListTraverse();

}
