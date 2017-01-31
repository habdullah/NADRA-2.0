//latest

#include <iostream>
#include <cstdlib>
#include<conio.h>
#include <string>
#include <conio.h>
#include <time.h>

using namespace std;
//cnic 
//

//class definiton of binary fmamily tree
class BinarySearchTree
{
public:
	
	struct tree_node
	{
		tree_node* left ;
		tree_node* right ;
		tree_node* wife ;


		string fname;
		string mname;
		string lname;
		int age;//age
		int DOB; //DD-MM-YYYY
		int DOD ; //DD-MM-YYYY, 0 if not dead.
		int cnic;//5 digit
		string religion;
		//string mark_of_id;//0 if null
		int DOM ;
		char gender ;
		int FamilyID ;
	};





	tree_node* root;
	BinarySearchTree()
	{
		
		root = NULL;

	}


	bool isEmpty() const { return root == NULL; }
	//trend functions
	void avgAOD();
	void avgAOD1(tree_node*); //averge age of death
	void avgAOM();//average age of marraige
	void avgAOM1(tree_node*);
	void MCR();//most common religion

	//primary functions
	void viewIMfam(tree_node*, tree_node*); //view immidiate fam
	void viewFT(tree_node*); //view family tree
	void Editfamily(tree_node*); //edit a family tree.YOUR OWN family tree
	tree_node* createNFT();//create new family tree
	
	bool search0(int,int);
	bool search(int,tree_node*);
	//suporting functions for printing full tree function viewFT();
	void print1(tree_node*);
	void print(tree_node*, string);

	void AddFM(tree_node*, string, string, int, int);//add family member.works for create new family tree func
	tree_node* search01(int,int);//if you want to (return pointer to the searched item.null if not found) call this func.it will call the func below
	tree_node* search1(int,tree_node*);//return pointer to the searched item.null if not found
	tree_node* search02(int,tree_node*);//if you want to (returns pointer to nodde bef searched node (his child).will return null if no child) call this func.it'll call the func bellow
	tree_node* search2(int,tree_node*);//returns pointer to nodde bef searched node (his child).will return null if no child

};
//this is a global func
int  cnicgen()
{
	srand(time(NULL));
	int i=  rand() % 1000000;
	return i;

};

BinarySearchTree DB[20];

void BinarySearchTree::print1(tree_node* daroot) {
	print(daroot, "     ");
}
void BinarySearchTree::print(tree_node* node, string indent)
{
	if (!node) return;
	cout<< indent << "-" << node->fname<<" "<<node->mname<<" "<<node->lname<< endl;
	print(node->left, indent + "  ");
	print(node->right, indent + "  ");
}
//work for neeche wala function;
int Numberofpeople = 0;
int agecontainer = 0;
int age = 0;
void BinarySearchTree::avgAOD()
{
	tree_node* curr=root;
	
	
	avgAOD1(curr);

}
void BinarySearchTree::avgAOD1(tree_node* p){
	//
	if (p != NULL)
	{
		if (!p->left==NULL) avgAOD1(p->left);
		
			age=((p->DOD)%10000)-((p->DOB)%10000);
			Numberofpeople++;
			agecontainer+=age;

			if (!p->right==NULL) avgAOD1(p->right);
		cout<<"Average age of death is "<<(agecontainer/Numberofpeople)<<endl;//needs fixing
	}
	//
	}
void BinarySearchTree::avgAOM()
{
	tree_node* curr = root;

	avgAOM1(curr);
}
int marraigecontainer=0;
int numberofpeople = 0;
void BinarySearchTree::avgAOM1(tree_node*curr)
{

	
	if (curr != NULL)
	{
		if (!curr->left==NULL) avgAOM1(curr->left);
		{
			numberofpeople++;
			marraigecontainer=marraigecontainer + (((curr->DOB)%10000)-((curr->DOM)%10000));

		}
		if (!curr->right==NULL) avgAOM1(curr->right);
		cout<<"Average age of marraige is "<<(agecontainer/numberofpeople);//needs fixing
	}

}
void BinarySearchTree::MCR()
{

}
void BinarySearchTree::viewIMfam(tree_node* position,tree_node* pre_position)//postion is current person we're showing family of,prepos is the node bef him i.e his child
{
	system("cls");
	//small info
	cout<<"running ";
	_getch();
	cout<<" Father is :"<<(position->left)->fname<<" "<<(position->left)->mname<<" "<<(position->left)->lname<<endl;
	cout<<" Mother is :"<<(position->right)->fname<<" "<<(position->right)->mname<<" "<<(position->right)->lname<<endl;
	if(pre_position==NULL){}
	else{cout<<" Child is :"<<pre_position->fname<<" "<<pre_position->mname<<" "<<pre_position->lname<<endl<<endl<<endl;}
	//large info
	//yourself
	cout<<"YOU"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<" Name:"<<position->fname<<" "<<position->mname <<" "<<position->lname<<endl;
	cout<<" Age:"<<position->age<<endl;
	cout<<" Religion:"<<position->religion<<endl;
	cout<<" familyID:"<<position->FamilyID<<endl;
	cout<<" cnic:"<<position->cnic<<endl;
	cout<<" Date of BIRTH :"<<position->DOB<<endl;
	cout<<" Date of MARRAIGE:"<<position->DOM<<endl;
	cout<<" Date of DEATH:"<<position->DOD<<endl;
	cout<<"-------------------------------------"<<endl<<endl;


	//fathers
	cout<<" YOUR FATHER"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<" Name:"<<(position->left)->fname<<" "<<(position->left)->mname<<" "<<(position->left)->lname<<endl;
	cout<<" Age:"<<(position->left)->age<<endl;
	cout<<" Religion:"<<(position->left)->religion<<endl;
	cout<<" familyID:"<<(position->left)->FamilyID<<endl;
	cout<<" cnic:"<<(position->left)->cnic<<endl;
	cout<<" Date of BIRTH :"<<(position->left)->DOB<<endl;
	cout<<" Date of MARRAIGE:"<<(position->left)->DOM<<endl;
	cout<<" Date of DEATH:"<<(position->left)->DOD<<endl;
	cout<<"-------------------------------------"<<endl<<endl;
	//mothers
	cout<<"YOUR MOTHER"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<" Name:"<<(position->right)->fname<<" "<<(position->right)->mname<<" "<<(position->right)->lname<<endl;
	cout<<" Age:"<<(position->right)->age<<endl;
	cout<<" Religion:"<<(position->right)->religion<<endl;
	cout<<" familyID:"<<(position->right)->FamilyID<<endl;
	cout<<" cnic:"<<(position->right)->cnic<<endl;
	cout<<" Date of BIRTH :"<<(position->right)->DOB<<endl;
	cout<<" Date of MARRAIGE:"<<(position->right)->DOM<<endl;
	cout<<" Date of DEATH:"<<(position->right)->DOD<<endl;
	cout<<"-------------------------------------"<<endl<<endl;
	//childs
	if(!pre_position==NULL){
	cout<<"CHILD"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Name:"<<pre_position->fname<<" "<<pre_position->mname<<" "<<pre_position->lname<<endl;
	cout<<"Age:"<<pre_position->age<<endl;
	cout<<"Religion:"<<pre_position->religion<<endl;
	cout<<"familyID:"<<pre_position->FamilyID<<endl;
	cout<<"cnic:"<<pre_position->cnic<<endl;
	cout<<" Date of BIRTH :"<<pre_position->DOB<<endl;
	cout<<" Date of MARRAIGE:"<<pre_position->DOM<<endl;
	cout<<" Date of DEATH:"<<pre_position->DOD<<endl;
	cout<<"-------------------------------------"<<endl<<endl;
	_getch();
	}
	else{
		cout<<"CHILD"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"No child yet"<<endl;
		_getch();}

}
void BinarySearchTree::viewFT(tree_node* position)
{
	int id=position->FamilyID;
	/*int i=0;
	for (i; i < 20; i++)
	{
		if((DB[i].root)->FamilyID==id)
		{break;}
	}
	if (i == 20){ cout << " Something went wrong" << endl; return; }
	*/
	print1(DB[position->FamilyID].root);
}
void BinarySearchTree::Editfamily(tree_node* curr)
{
	int cnic;
	string fname;
	string mname;
	string lname;
	int age;
	int DOB;
	int DOM;
	int DOD;
	char gender;
	char option;
	int choice;
	int FamilyID;
	int cno;
	string religion;
	int i;
	while (1)
	{
		system("cls");
		cout<< " EDIT FAMILY" << endl;
		cout<< "------------------------------------" << endl;
		cout<< " 1.Add child." << endl;
		cout<< " 2.Add wife" << endl;
		cout<< " 3.return to menu." << endl;
		cout<< " Enter your choice :" << endl;
		cin >> choice;
		if (choice == 1)
		{
			//see if he is not root.if not then can't add child
			if (!(curr==DB[curr->FamilyID].root)){
				cout << " you already have a child" << endl;
				cout << " Press any key to return" << endl;
				_getch();
				continue;
			}
			//if root
			{
				if (curr->wife == NULL)
				{
					cout << " You're not married yet." << endl;
					cout << " Press any key to return" << endl;
					_getch();
				
					continue;
				}
				if (!curr->wife == NULL)
				{
					//add child now
					//node creartion
					
					cnic= cnicgen();//cnic generated;
					cout << " Enter First Name:";	
					cin>>fname;
					cout<<" Enter middle name (enter 0 if no middle name):";
					cin>>mname;	
					if(mname =="0"){
					mname="";}
					cout<<" Enter last name (0 if no last name):";
					cin>>lname;	
					if(lname =="0"){
					lname="";}
					cout << " Enter Age:";
					cin >> age;		
					cout << " Enter Religion:";
					cin>>religion;
					cout << " Enter Date of birth(DDMMYYYY):";
					cin >> DOB;
					cout << " Enter Date of marraige(DDMMYYY)(ebter '0' if not applied):";
					cin >> DOM;
					cout << " Enter Date of death(DDMMYYYY) (If still alive Enter '0'):";
					cin >> DOD;
					cout << " Enter Gender (M/F):";
					cin >> gender;
					FamilyID = curr->FamilyID;


					tree_node* newgy = new tree_node;
					DB[curr->FamilyID].root = newgy;
					newgy->fname = fname;
					newgy->mname = mname;
					newgy->lname = lname;
					newgy->age = age;
					newgy->cnic = cnic;
					newgy->DOB = DOB;
					newgy->DOD = DOD;
					newgy->DOM = DOM;
					newgy->gender = gender;
					newgy->FamilyID = FamilyID;
					newgy->religion=religion;
					newgy->left = curr;//pointer from child to father set
					newgy->right = curr->wife;
					newgy->wife=NULL;



					cout << " child registered" << endl;
					cout << " Press any key to return..." << endl;
					_getch();
					system("cls");
					break;
				}
				else
				{
					cout << " Something went wrong..."; continue;
				}
			}
		}
		if (choice == 2)
		{
			cout << " Enter her CNIC No:" << endl;
			
			cin >> cnic;
			tree_node* newwife;
			for ( i = 0; i < 20; i++)
				{
					if (!DB[i].isEmpty())
					newwife = DB[i].search01(cnic,i);
					cout<<fname<<" "<<mname<<" "<<lname;///fttttttttttttttttttttttttttttttttttttttttt
				if (!newwife == NULL)
			{
				//dont register her.just add her;
				if (newwife->gender == 'M'||newwife->gender == 'm')
				{
					//she's a male.you cannot marry a male
					cout << "New wife" << endl;
					cout << "-------------------------------------" << endl;
					cout << " Name:" << curr->fname <<" "<<curr->mname<<" "<<curr->lname<< endl;
					cout << " Age:" << curr->age << endl;
					cout << " Religion:" << curr->religion << endl;
					cout << " familyID:" << curr->FamilyID << endl;
					cout << " cnic:" << curr->cnic << endl;
					cout << " Date of BIRTH :" << curr->DOB << endl;
					cout << " Date of MARRAIGE:" << curr->DOM << endl;
					cout << " Date of DEATH:" << curr->DOD << endl;
					cout << "-------------------------------------" << endl << endl;
					cout << " This person is a MALE \n Can not register a male as your wife\n Press any key to return to menu..." << endl << endl;
					_getch();
					
					continue;
				}
				else if (newwife->gender == 'F'||newwife->gender == 'f'){
				cout << "New wife" << endl;
				cout << "-------------------------------------" << endl;
				cout << " Name:" << curr->fname <<" "<<curr->mname<<" "<<curr->lname<< endl;
				cout << " Age:" << curr->age << endl;
				cout << " Religion:" << curr->religion << endl;
				cout << " familyID:" << curr->FamilyID << endl;
				cout << " cnic:" << curr->cnic << endl;
				cout << " Date of BIRTH :" << curr->DOB << endl;
				cout << " Date of MARRAIGE:" << curr->DOM << endl;
				cout << " Date of DEATH:" << curr->DOD << endl;
				cout << "-------------------------------------" << endl << endl;
				cout << " Register this person as your wife? (y/n)" << endl << endl;
				char option1;
				cin >> option1;
				{
					if (option1 == 'Y' || option1 == 'y')
					{
						curr->wife = newwife;
						cout << " Registered" << endl << " Press any key to return to menu...";
						_getch();
						system("cls");
						break;
					}
					else
					{
						cout << " Press any key to return..." << endl;
						_getch();
						system("cls");
						break;
					}

				}
				}

			}
				}
		

			if (i==20 )
			{
				cout << " This CNIC is not registered with the database,create her database ?(Y/N):" << endl;
				cin >> option;
				if (option == 'Y' || option == 'y')
				{//register her first
				 i = 0;
					for (i; i < 20; i++)
					{
						if (DB[i].isEmpty()){ break; }

					}

					if (i == 20)
					{
						cout << "Sorry can't add wife.database full.\n Press any key to return to menu...";
						_getch();
						system("cls");
						continue;
					}
					
					

					cno = cnicgen();
					cout << " The CNIC assigned to her is " << cno << endl;
					cout<<" Enter first name :";
	
					cin>>fname;
					cout<<" Enter middle name (enter 0 if no middle name):";
					cin>>mname;	
					if(mname =="0"){
					mname="";}
					cout<<" Enter last name (0 if no last name):";
					cin>>lname;	
					if(lname =="0"){
					lname="";}
					cout << " Enter Age:";
					cin >> age;
					cout << " Enter Religion:";
					cin>>religion;
					cout << " Enter Date of birth(DDMMYYYY):";
					cin >> DOB;
					cout << " Enter Date of marraige(DDMMYYY):";
					cin >> DOM;
					cout << " Enter Date of death(DDMMYYYY) (If still alive Enter '0'):";
					cin >> DOD;
					cout << endl;

					


					tree_node* newwife = new tree_node;
					DB[i].root = newwife;
					FamilyID = i;
					newwife->fname = fname;
					newwife->mname = mname;
					newwife->lname = lname;
					newwife->age = age;
					newwife->cnic = cno;
					newwife->DOB = DOB;
					newwife->DOD = DOD;
					newwife->DOM = DOM;
					newwife->gender = 'F';
					newwife->FamilyID = FamilyID;
					newwife->religion=religion;
					newwife->left=NULL;
					newwife->right=NULL;
					newwife->wife=NULL;
					curr->wife = newwife;//pointer from child to father set
					

					//print her info
					cout<< "New wife" << endl;
					cout<< "-------------------------------------" << endl;
					cout<< " Name:" << newwife->fname<<" "<<newwife->mname<<" "<<newwife->lname <<endl;
					cout<< " Age:" << newwife->age << endl;
					cout<< " Religion:" << newwife->religion << endl;
					cout<< " familyID:" << newwife->FamilyID << endl;
					cout<< " cnic:" << newwife->cnic << endl;
					cout<< " Date of BIRTH :" << newwife->DOB << endl;
					cout<< " Date of MARRAIGE:" << newwife->DOM << endl;
					cout<< " Date of DEATH:" << newwife->DOD << endl;
					cout<< "-------------------------------------" << endl << endl;

					cout << " Register this person as your wife? (y/n)" << endl << endl;
					char option1;
					cin >> option1;
					{
						if (option1 == 'Y' || option1 == 'y')
						{
							curr->wife = newwife;
							cout<< " Registered" << endl << " Press any key to return to menu...";
							_getch();
							system("cls");
							continue;
						}
						else
						{
							cout << " Press any key to return..." << endl;
							_getch();
							system("cls");
						}

					}
				}
				else
				{
					cout << " Press any key to return..." << endl;
					_getch();
					system("cls");
				}
			}
			
		}
		if (choice == 3){ system("cls"); return; }
		else{
			cout << " Invalid choice.";
			cout << " Press any key to return" << endl;
			_getch();
			system("cls");
		}
	}

	
	
}
BinarySearchTree::tree_node* BinarySearchTree::createNFT()
{
	int cnic;
	string fname;
	string mname;
	string lname;
	int age;
	int DOB;
	int DOM;
	int DOD;
	char gender;
	char option;
	int choice;
	int FamilyID;
	int cno;
	string religion;
	
		int i = 0;
	for(i;i<20;i++)
	{
		if(DB[i].isEmpty())
		{
			break;
		}
	}
	if (i==20)
		{
			cout<<" Database is full!"<<endl<<" Press any key to return...";
			_getch();
			system("cls");
			return NULL;
		}
	//node creartion
	cnic=cnicgen();//cnic generated;
	cout << " The CNIC assigned is : " << cnic<< endl;
	cout<<" Enter first name ";
	
	cin>>fname;
	cout<<" Enter middle name (enter 0 if no middle name)";
	cin>>mname;	
	if(mname =="0"){
	mname="";}
	cout<<" Enter last name (0 if no last name)";
	cin>>lname;
	if(lname =="0"){
	lname="";}

	cout<<" Enter your Age:";
	cin>>age;
	cout<<" Enter your Date of birth:";
	cin>>DOB;
	cout<<" Enter your Gender:";
	cin>>gender;
	cout<<" Enter your religion:";
	cin>>religion;
	 FamilyID=i;

	tree_node* newguy=new tree_node;
	newguy->fname=fname;
	newguy->mname=mname;
	newguy->lname=lname;
	newguy->age=age;
	newguy->cnic=cnic;
	newguy->DOB=DOB;
	newguy->DOD=0;
	newguy->gender=gender;
	newguy->FamilyID=FamilyID;
	newguy->religion=religion;
	newguy->left=NULL;
	newguy->right=NULL;
	newguy->wife=NULL;
	DB[i].root = newguy;
	AddFM(newguy,"Father","Mother",i,1);

	cout<<" Your Database has been added";
	return DB[i].root;
}


void BinarySearchTree::AddFM(tree_node* newguy,string s1,string s2,int familyID,int jugar)
{
	int cnic=0;
	string fname;
	string mname;
	string lname;
	int age=0;
	int DOB=0;
	int DOM=0;
	int DOD=0;
	char gender;
	char option=0;
	int choice=0;
	int FamilyID;
	string religion;

	if(jugar==1)
	{

		//adding father node
		cout<<"-------------\nAdd "<<s1<<" Info ? (y/n)";
			  
		cin>>option;
		if(option=='Y'||option=='y')
		{
			//node creartion
			  cnic=cnicgen();//cnic generated;
			cout << " The CNIC assigned is :" << cnic << endl;
			cout<<" Enter first name :";
	
	cin>>fname;
	cout<<" Enter middle name (enter 0 if no middle name):";
	cin>>mname;	
	if(mname =="0"){
	mname="";}
	cout<<" Enter last name (0 if no last name):";
	cin>>lname;
	if(lname =="0"){
	lname="";}


			cout<<" Enter Age:";
			cin>>age;
			cout<<" Enter religion:";
			cin>>religion;
			cout<<" Enter Date of birth(DDMMYYYY):";
			cin>>DOB;
			cout<<" Enter Date of marraige(DDMMYYY):";
			cin>>DOM;
			cout<<" Enter Date of death(DDMMYYYY) (If still alive Enter '0'):";
			cin>>DOD;
			
		  FamilyID=familyID;
			

			tree_node* newgy=new tree_node;
			newgy->fname=fname;
			newgy->mname=mname;
			newgy->lname=lname;
			newgy->age=age;
			newgy->cnic=cnic;
			newgy->DOB=DOB;
			newgy->DOD=DOD;
			newgy->DOM=DOM;
			newgy->gender='M';
			newgy->religion=religion;
			newgy->left=NULL;
			newgy->right=NULL;
			newguy->wife=NULL;
			newgy->FamilyID=FamilyID;
			newguy->left = newgy;//pointer from child to father set
				AddFM(newgy,s1+"'s Father","Father's "+ s2,familyID,0);
		}
		else
		{
		
		
		
		
		}

		//adding mother node

		cout<<"-------------\nAdd "<<s2<<" Info ? (y/n)";
		 
		cin>>option;
		if(option=='Y'||option=='y')
		{
			//node creartion
			int cnic=cnicgen();//cnic generated;
			cout << " The CNIC assigned is :" << cnic << endl;
			cout<<" Enter first name :";
	
	cin>>fname;
	cout<<" Enter middle name (enter 0 if no middle name):";
	cin>>mname;	
	if(mname =="0"){
	mname="";}
	cout<<" Enter last name (0 if no last name):";
	cin>>lname;
	if(lname =="0"){
	lname="";}
	

			cout<<" Enter Age:";
			cin>>age;
			cout<<" Enter religion:";
			cin>>religion;			
			cout<<" Enter Date of birth(DDMMYYYY):";
			cin>>DOB;
			cout<<" Enter Date of marraige(DDMMYYY):";
			cin>>DOM;
			cout<<" Enter Date of death(DDMMYYYY) (If still alive Enter '0'):";
			cin>>DOD;
		 
		 FamilyID=familyID;


			tree_node* newgy=new tree_node;
			newgy->fname=fname;
			newgy->mname=mname;
			newgy->lname=lname;
			newgy->age=age;
			newgy->cnic=cnic;
			newgy->DOB=DOB;
			newgy->DOD=DOD;
			newgy->DOM = DOM;
			newgy->gender='F';
			newgy->religion=religion;
			newgy->left=NULL;
			newgy->right=NULL;
			newgy->wife=NULL;
			newgy->FamilyID=FamilyID;
			newguy->right = newgy;//pointer from child to father set
				AddFM(newgy,s2+"'s Father",s2+"'s mother",familyID,0);
		}
		else
		{
		
		
		 
		return;
		}
	}
	if(jugar==0)
	{
		//adding father node
		cout<<"-------------\nAdd "<<s1<<" Info ? (y/n)";
				cin>>option;
		if(option=='Y'||option=='y')
		{
			//node creartion
			int cnic=cnicgen();//cnic generated;
			cout << " The CNIC assigned is :" << cnic << endl;
			cout<<" Enter first name :";
	
	cin>>fname;
	cout<<" Enter middle name (enter 0 if no middle name):";
	cin>>mname;	
	if(mname =="0"){
	mname="";}
	cout<<" Enter last name (0 if no last name):";
	cin>>lname;
	if(lname =="0"){
	lname="";}


			cout<<" Enter Age:";
			cin>>age;
			cout<<" Enter religion:";
			cin>>religion;
			cout<<" Enter Date of birth(DDMMYYYY):";
			cin>>DOB;
			cout<<" Enter Date of marraige(DDMMYYY):";
			cin>>DOM;
			cout<<" Enter Date of death(DDMMYYYY) (If still alive Enter '0'):";
			cin>>DOD;
			FamilyID=familyID;

			tree_node* newgy=new tree_node;
			newgy->fname=fname;
			newgy->mname=mname;
			newgy->lname=lname;
			newgy->age=age;
			newgy->cnic=cnic;
			newgy->DOB=DOB;
			newgy->DOD=DOD;
			newgy->DOM=DOM;
			newgy->gender='M';
			newgy->religion=religion;
			newgy->left=NULL;
			newgy->right=NULL;
			newgy->wife=NULL;
			newgy->FamilyID=FamilyID;
			newguy->left = newgy;//pointer from child to father set
				AddFM(newgy,s1+"'s Father",s1+"'s Mother",familyID,0);
		}
		else
		{
	
		 
		
		}

		//adding mother node

		cout<<"-------------\nAdd "<<s2<<" Info ? (y/n)";
		 
		cin>>option;
		if(option=='Y'||option=='y')
		{
			//node creartion
			int cnic=cnicgen();//cnic generated;
			cout << " The CNIC assigned to her is :" << cnic << endl;
			cout<<" Enter first name :";
	
	cin>>fname;
	cout<<" Enter middle name (enter 0 if no middle name):";
	cin>>mname;	
	if(mname =="0"){
	mname="";}
	cout<<" Enter last name (0 if no last name):";
	cin>>lname;
	if(lname =="0"){
	lname="";}
	

			cout<<" Enter Age:";
			cin>>age;		
			cout<<" Enter religion:";
			cin>>religion;
			cout<<" Enter Date of birth(DDMMYYYY):";
			cin>>DOB;
			cout<<" Enter Date of marraige(DDMMYYY):";
			cin>>DOM;
			cout<<" Enter Date of death(DDMMYYYY) (If still alive Enter '0'):"; 
			cin>>DOD;
		 
			 FamilyID=familyID;

			tree_node* newgy=new tree_node;
			newgy->fname=fname;
			newgy->mname=mname;
			newgy->lname=lname;
			newgy->age=age;
			newgy->cnic=cnic;
			newgy->DOB=DOB;
			newgy->DOD=DOD;
			newgy->DOM=DOM;
			newgy->gender='F';
			newgy->religion=religion;
			newgy->left=NULL;
			newgy->right=NULL;
			newgy->wife=NULL;
			newgy->FamilyID=FamilyID;
			newguy->right = newgy;//pointer from child to father set
				AddFM(newgy,s1+"'s Father",s1+"'s Mother",familyID,0);
		}
		else
		{
		 
		return;
		}
	}
}
bool BinarySearchTree::search0(int cno,int i)
{ 
	bool yes = search(cno, DB[i].root);
	
	 return yes;
}
bool BinarySearchTree::search(int cno,tree_node* p)
{
	
	if (p != NULL)
	{
		if (!(p->left==NULL)) search(cno,p->left);
		if (p->cnic == cno)
		{
			return true;
		}
		if (!(p->right==NULL)) search(cno,p->right);
	}
	else
	{
		return false;
	}
}
BinarySearchTree::tree_node* BinarySearchTree::search01(int cno,int i)
{
	cout<<" search01 running \n";
	tree_node* yes=search1(cno,(DB[i].root));

	if(!(yes==NULL))//if true
		{
			return yes;
		}
	 else
		 cout<<" Returning 0";
	_getch();
		 return NULL;

	
}
BinarySearchTree::tree_node* BinarySearchTree::search1(int cno,tree_node* p)
{
	cout<<" Search1 running \n";
	
	{ 
		if (p->cnic == cno)
			cout<<" FOUND";return p;
		if (!p->left==NULL) search1(cno,p->left);
		if (!p->right==NULL) search1(cno,p->right);
	}
	
}
BinarySearchTree::tree_node* BinarySearchTree::search02(int cnic,tree_node* p)
{
	return search2(cnic,p);
}

BinarySearchTree::tree_node* BinarySearchTree::search2(int cno,tree_node* p)

{
	
	//we have eliminated the possibility that p* does not have any children.HE HAS CHILDREN.
	
	
	{
		if((p->left)->cnic==cno||(p->right)->cnic==cno){return p;};
		if (!p->left==NULL) search2(cno,p->left);
		if (!p->right==NULL) search2(cno,p->right);
	}
	
}




int main()
{

	
			

	int ch;
	bool found = false;
	bool exitcon = true;
	BinarySearchTree::tree_node* banda = NULL;
	BinarySearchTree::tree_node* pre_banda = NULL;
	int tmp = 0, tmp1 = 0, cnic = 0;


	int id = 0;
	int i = 0;
	int opt;
	int iid = 0;
	while (exitcon)
	{

		foo:
		i = 0;
		cnic = 0;
		ch=0;
		opt=0;
		banda = NULL;
		pre_banda = NULL;

		system("cls");
		system("color A1");
		cout << endl << endl;
		cout << " NADRA 2.0 " << endl << endl;
		cout << " ------------------------------------------------------------" << endl;

		cout << " 1. Search for your family tree." << endl;
		cout << " 2. Make new family tree." << endl;
		cout << " 3. Exit " << endl;
		cout << " Enter your choice : ";
		
		cin >> opt;
		system("cls");

		if (opt == 1)
		{
			system("color A");
			cout << endl << " Please enter your CNIC number :";
			cin >> cnic;
			cout << endl;
			//searching the array of binary trees for the person.
			for (i = 0; i < 20; i++)
			{
				cout<<" The loop";
				if (!DB[i].isEmpty())
				{
					
					//cout<< DB[i].search0(cnic, i)<<endl;
					//if (found == true){ cout << " Found is true"; }
					//if (found == false){ cout << " nopes"; exitcon = false; break; }


					cout<<" this worked";
					_getch();
					banda = DB[i].search01(cnic, i);//function stores the pointer to the person's node permanently in banda var
					cout<<banda->fname;
				}
				if (!banda == NULL)
				{
					//id = banda->FamilyID;
					exitcon = false;
					break;


				}
			}
			if (i == 20)
			{
				//person not found
				cout << " Invalid CNIC number.Person not found! " << endl << " Press enter to return..." << endl;
				cnic = 0;
				_getch();
			}

		}

	if (opt == 2)
			{
	
				//make new family tree wala function
				//createNFT();
				BinarySearchTree::tree_node* root;
				root = DB[0].createNFT();
				if (!root == NULL){
					cnic = ((root)->cnic);
					id = root->FamilyID;
					banda = root;
					system("cls");
					exitcon = false;
					 
				}
				else
					cout<<" Somethign went wrong";
			}

			system("cls");
			if (opt == 3){ cout << " Exiting"; exit(1); }
		
	}
	system("color");
	exitcon = true;
	bool exitcon1=true;


	while (exitcon1)
	{
		cout << endl << endl;
		cout << "Family Tree Operations " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. View immediate family " << endl;//views father mother and children
		cout << " 2. View full family Tree " << endl;//full family tree
		cout << " 3. Edit family Tree " << endl;
		cout << " 4. View trends in family " << endl;
		//cout << " 5. Create your own family tree " << endl;
		cout << " 6. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:


			cout<<id;
			cout<<banda->fname;
			cout<<banda->cnic;
			cout<<banda->FamilyID;
			cout<<DB[banda->FamilyID].root->fname;
			cout<<cnic;
			_getch();

			if(banda->cnic==cnic&&banda==DB[banda->FamilyID].root){pre_banda=NULL;}
			else
			{pre_banda = DB[id].search02(cnic,DB[id].root);//return pointer to node bef the person's node,i.e his child
					
					if (pre_banda==NULL)
					{
					
						system("cls");
						cout << " no child .loading"<<endl;
						
						
					}
			}
			
		DB[id].viewIMfam(banda,pre_banda);//code is written but has bugs.
			break;
		case 2:
			DB[id].viewFT(banda);
			break;
		case 3:
			DB[id].Editfamily(banda);
			
			break;
		case 4:
			break;
		case 5:

			break;
		case 6:
			cout << " Exiting...";
			
			bool exitcon1=false;
		exitcon = true;
		goto foo;
		
			
			
		}
	}

	
} 

