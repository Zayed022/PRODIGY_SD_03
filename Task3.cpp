#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
using namespace std;
class contact{
    long long ph;
    char name[20];
    char add[20];
    char email[20];
    public:
    void create_contact(){
        cout<<"Phone: ";
        cin>>ph;
        cout<<"Name: ";
        cin>>name;
        cout<<"Address: ";
        cin>>add;
        cout<<"Email: ";
        cin>>email;
        cout<<"\n";
    }
    void show_contact(){
        cout<<endl<<"Phone: "<<ph;
        cout<<endl<<"Name: "<<name;
        cout<<endl<<"Address: "<<add;
        cout<<endl<<"Email Address: "<<email;
    }
    long getPhone(){
        return ph;
    }
    char* getName(){
        return name;
    }
    char* getAddress(){
        return add;
    }
    char* getEmail(){
        return email;
    }
};
fstream fp;
contact cont;
void save_contact(){
    fp.open("contactBook.dat",ios::out|ios::app);
    cont.create_contact();
    fp.write((char*)&cont,sizeof(contact));
    fp.close();
    cout<<endl<<endl<<"Contact Has Been Successfully Created. ";
    getchar();
}
void show_all_contacts(){
    system("cls");
    cout<<"\n\t\t-------------LIST OF CONTACTS------------\n\t\t";
    fp.open("contactBook.dat",ios::in);
    while(fp.read((char*)&cont,sizeof(contact))){
        cont.show_contact();
        cout<<endl<<"========================================";
    }
    fp.close();
}
void display_contact(int num){
    bool found;
    int ch;
    found=false;
    fp.open("contactBook.dat",ios::in);
    while(fp.read((char*)&cont,sizeof(contact))){
        if(cont.getPhone()==num){
            system("cls");
            cont.show_contact();
            found=true;
        }
    }
    fp.close();
    if(found==false){
        cout<<"\n\nNo record found...";
    }
    getchar();
}
void edit_contact(){
    int num;
    bool found=false;
    system("cls");
    cout<<"....Edit Contact\n.."<<endl;
    cout<<"Enter the Contact to Edit:";
    cin>>num;
    fp.open("contactBook.dat",ios::in|ios::out);
    while(fp.read((char*)&cont,sizeof(contact)) && found==false){
        if(cont.getPhone()==num){
            cont.show_contact();
            cout<<"\nPlease enter the new details of the contact: "<<endl;
            cont.create_contact();
            int pos=-1*sizeof(cont);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&cont,sizeof(cont));
            cout<<endl<<endl<<"\tContact Successfully Updated...";
            found=true;
        }
    }
    fp.close();
    if(found==false) cout<<endl<<endl<<"Contact Not Found...";

}
void delete_contact(){
    int num;
    system("cls");
    cout<<endl<<endl<<"please Enter the Contact: ";
    cin>>num;
    fp.open("contactBook.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&cont,sizeof(contact))){
        if(cont.getPhone()!=num){
            fp2.write((char*)&cont,sizeof(contact));
        }
    }
    fp2.close();
    fp.close();
    remove("contactBook.dat");
    rename("Temp.dat","contactBook.dat");
    cout<<endl<<endl<<"\tContact Deleted...";
    
}
int main(int argc,char* argv[]){
    system("cls");
    system("color 03");
    cout<<"\t\t\t\t*\t\t*";
    cout<<"\t\t\t\t**\t**";
   	cout<<"\t\t\t\t***\t***";
   	cout<<"\t\t\t\t****\t****";
   	cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
   	cout<<"\t\t\t\t*******\t*******";
   	cout<<"\t\t\t\t*******\t*******";
   	cout<<"\t\t\t\t******\t******";
   	cout<<"\t\t\t\t*****\t*****";
   	cout<<"\t\t\t\t****\t****";
   	cout<<"\t\t\t\t***\t***";
   	cout<<"\t\t\t\t**\t**";
   	cout<<"\t\t\t\t*\t*";
    for(;;){
        int ch;
        cout<<"\n\t ****Welcome to Contact Management System ****";
        cout<<"\n\n\n\t\t Main Menu\n\t\t=======\n\t\t[1].Add a new Contact.\n\t\t[2].List all Contact.\n\t\t[3].Search for contact.\n\t\t[4].Edit a Contact.\n\t\t[5].Delete a Contact.\n\t\t[0].Exit.\n\t\t======\n\t\t";
        cout<<"Enter Your Choice";
        cin>>ch;
        switch(ch){
            case 0:cout<<"\n\n\tThank You for using CMS...";
                    exit(0);
                    break;
            break;
            case 1:save_contact();
                    break;
            case 2:show_all_contacts();
                    break;
            case 3:int num;
                    system("cls");
                    cout<<"\n\n\tPhone: ";
                    cin>>num;
                    display_contact(num);
                    break;
            case 4:edit_contact();
                    break;
            case 5:delete_contact();
                    break;
            default:
                    break;
        }
        int opt;
        cout<<"\n\n\nEnter the Choice: \n\n\t[1]Main Menu.\t\t.[0].Exit\n";
        cin>>opt;
        switch(opt){
            case 1:
                    system("cls");
                    continue;
            case 0: exit(0);  
        }
        
    }
    return 0;
}
