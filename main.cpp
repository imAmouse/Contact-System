#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;


class person {
private:
    string name,num_phone,num_qq,address;
    bool judge; //判断此数据是否有效，以便于增删、查找、浏览操作
public:
    person();
    void set_name(string name) {this->name=name;}
    void set_num_phone(string num_phone) {this->num_phone=num_phone;}
    void set_num_qq(string num_qq) {this->num_qq=num_qq;}
    void set_address(string address) {this->address=address;}
    void set_judge(bool judge) {this->judge=judge;}
    string get_name() {return name;}
    string get_num_phone() {return num_phone;}
    string get_num_qq() {return num_qq;}
    string get_address() {return address;}
    bool get_judge() {return judge;}
};
person::person():judge(false) {}


class book {
private:
    person contact[1000];//每个电话本最大容量为1000
    bool weizhi; //false为电话内部，true为存储卡存储
public:
    book(bool weizhi);
    bool get_weizhi(){return weizhi;}//返回值false为电话内部，true为存储卡存储
    void add_person();
    void delete_person(string name); //传入要删除的编号
    void revise_person(string name); //修改
    void find_person(string name); //查询
    void look_though(); //浏览全部
    void transfer(bool j); //转存：False:phone to card True:card to phone
    bool get_judge(int PhoneNum){return contact[PhoneNum].get_judge();}
    void Save();
};
book::book(bool weizhi):weizhi(weizhi) {}
void book::add_person() {
    int num;
    for (int i = 0; i < 1000; i++) {
        if (contact[i].get_judge() == false)
            num = i;
    }
    string temp;
    bool judge;
    cout << "请输入联系人姓名：\n";
    cin >> temp;
    contact[num].set_name(temp);
    contact[num].set_judge(true);
    cout << "是否记录电话号码？(1/0)";
    cin >> judge;
    if (judge) {
        cout << "请输入：";
        cin >> temp;
        contact[num].set_num_phone(temp);
    }
    cout << "是否记录QQ号码？(1/0)";
    cin >> judge;
    if (judge) {
        cout << "请输入：";
        cin >> temp;
        contact[num].set_num_qq(temp);
    }
    cout << "是否记录联系人地址？(1/0)";
    cin >> judge;
    if (judge) {
        cout << "请输入：";
        cin >> temp;
        contact[num].set_address(temp);
    }
    cout << "添加成功！\n";
}
void book::delete_person(string name) {
    cout<<"删除成功！\n";
}
void book::revise_person(string name) {

    cout<<"修改成功！\n";
}
void book::find_person(string name) {
    for(int i=0;i<1000;i++){
        if(name==contact[i].get_name()) {

            cout << contact[i].get_name() << "\t" << contact[i].get_num_phone() << "\t\t" << contact[i].get_num_qq() << "\t\t"
                 << contact[i].get_address();
            if (!weizhi)
                cout << "\t内部" << "\t" << i << "\n";
            if (weizhi)
                cout << "\t储存卡" << "\t" << i << "\n";
        }
    }
}
void book::look_though() {
    for(int i=0;i<1000;i++)
        if(contact[i].get_judge()==true) {
            cout << contact[i].get_name() << "\t" << contact[i].get_num_phone() << "\t\t" << contact[i].get_num_qq() << "\t\t"
                 << contact[i].get_address() ;
            if (!weizhi)
                cout << "\t内部" << "\t" << i << "\n";
            if (weizhi)
                cout << "\t储存卡" << "\t" << i << "\n";
        }
    }
void book::Save() {
    string str;
    if(!weizhi)
        str="PhoneIn.ini";
    else if(weizhi)
        str="PhoneSdCard.ini";
    fstream tooo(str);
    for(int i=0;i<1000;i++){
        if(contact[i].get_judge()) {
            tooo << contact[i].get_name() << ends << contact[i].get_num_phone() << ends << contact[i].get_num_qq()
                 << ends << contact[i].get_address() << endl;
        }
    }
}



int main() {
    book phone_in(false), phone_card(true); //定义手机通讯录 、储存卡通讯录
    while (true) {
        cout << "************************************\n";
        cout << "*                                  *\n";
        cout << "*　　　　　通讯录管理系统              *\n";
        cout << "*　　　请输入数字来进行有关操作：       *\n";
        cout << "*　　　1、 添加联系人                 *\n";
        cout << "*　　　2、 删除联系人                 *\n";
        cout << "*　　　3、 查找联系人                 *\n";
        cout << "*　　　4、 修改已经存在的联系人信息     *\n";
        cout << "*　　　5、 浏览已经存在的联系人信息     *\n";
        cout << "*　　　9、 退出系统                   *\n";
        cout << "*                                  *\n";
        cout << "************************************\n";
        int num;
        string name;
        cin >> num;
        switch (num) {
            case 1: //添加联系人
                while (true) {
                    cout << "请选择存储位置：\n1、内部\t2、储存卡\n";
                    cin >> num;
                    if (num == 1) {
                        phone_in.add_person();
                        break;
                    } else if (num == 2) {
                        phone_card.add_person();
                        break;
                    } else {
                        cout << "错误！请输入正确的号码：\n";
                    }
                }break;
            case 2: //删除联系人
                while (true) {
                    cout<<"请输入联系人姓名：\n";
                    cin>>name;
                    cout<<"姓名\t电话号\tQQ号\t地址\t内部&存储卡\t序号\n";
                    phone_in.find_person(name);
                    phone_card.find_person(name);
                    cout<<"是否还要删除其他联系人？(Y/N)";
                    cin>>name;
                    if(name=="n"||name=="N")break;
                }break;
            case 3: //查找联系人
                while(true) {
                    cout<<"请输入被查找姓名：\n";
                    cin>>name;
                    cout<<"姓名\t电话号\tQQ号\t地址\t内部&存储卡\t序号\n";
                    phone_in.find_person(name);
                    phone_card.find_person(name);
                    cout<<"你想查找其他联系人吗？(Y/N)\n";
                    cin>>name;
                    if(name=="N"||name=="n")
                        break;
                }break;
            case 4: //修改联系人
                while(true) {
                    cout << "请输入联系人姓名：";
                    cin >> name;
                    cout<<"是否还要修改其他联系人？(Y/N)";
                    cin>>name;
                    if(name=="n"||name=="N")break;

                }break;
            case 5: //浏览已存储联系人
                cout<<"姓名\t电话号\tQQ号\t地址\t内部&存储卡\t序号\n";
                phone_in.look_though();
                phone_card.look_though();
                break;
            case 9: //退出系统并保存
                phone_in.Save();
                phone_card.Save();
                return 0;
            default:
                cout << "错误！请输入正确的号码！\n";
        }
    }
}