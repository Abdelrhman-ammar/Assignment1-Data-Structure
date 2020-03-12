#include <iostream>
#include <string>
using namespace std;
class StudentName {
private:
     string name;
public:
    int get_no_space()
    {
        int no_space = 0;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] == ' ')
            {
                no_space++;
            }
        }
        return no_space;
    }
    void clear_name()
    {
        string new_name = "";
        int counter = 0,len_word=name.length();
        for (int i = 0; i < len_word; i++)
        {
            if (name[i] == ' '&&name[i+1]!=' ')
            {
                if (new_name.empty())
                {
                    continue;
                }
                else if(i!=len_word-1)
                {
                     
                    new_name += " ";
                }
            }
            else if (name[i] == ' ' && name[i + 1] == ' ')
            {
                continue;
            }
            else
            {
                if (name[i]==' ')
                {
                    continue;
                }
                
                new_name += name[i];
            }
            
        }
        name = new_name;
        
    }
    StudentName()
    {
        int no_space = 0;
        string last_word = "";
        cout << "enter name: " << endl;
        getline(cin,name);
        while(name.empty())
        {
            cout << "enter name: " << endl;
            getline(cin, name);
        }
        clear_name();
        no_space = get_no_space();
        if (no_space == 1)
        {
            for (int i = name.length()-1;i>-1; i--)
            {
                if (name[i] != ' ')
                {
                    last_word += name[i];
                }
                else
                {
                    break;
                }  
            }
            reverse(last_word.begin(), last_word.end());
            name =name+" "+last_word;
            
        }
        else if (no_space == 0)
        {
            name = name + " " + name + " " + name;
        }
  
    }
    void print()
    {
        int counter = 1;
        cout << "(" << counter << ")";
        for (int i = 0; i < name.length(); i++)
        {
            
            if (name[i] != ' ')
                cout << name[i];
            else
            {
                counter++;
                cout << endl;
                cout << "(" << counter << ")";
            }
        }
        cout << endl;
    }
    string word_at_position(int position)
    {
        string w="";
        int spaces = 0;
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] != ' ')
            {
                if (position - 1 == spaces)
                {
                    w += name[i];
                }
            }
            else
            {
                spaces++;
            }
        }
        return w;
    }
    void  replace(int i,int j)
    {
        int spaces = get_no_space();
        if (i > spaces + 1 || j > spaces + 1||i<0||j<0)

        {
            cout << "false" << endl;
        }

        else
        {
            int counter = 0;
            string word_for_i, word_for_j;
            string *arr= new string[spaces +1];
            for (int i = 0; i < name.length(); i++)
            {
                if (name[i] == ' ')
                {
                    counter++;
                    continue;
                }
                else
                {
                    arr[counter] += name[i];
                }
            }
           
            word_for_i = word_at_position(i);
            word_for_j = word_at_position(j);
            arr[i-1]= word_at_position(j);
            arr[j-1] = word_at_position(i);

            name = "";
            for (int i = 0; i < spaces + 1; i++)
            {
                 
                if (i == 0)
                {
                    name = name + arr[i];

                }
                else
                {
                    name = name +" " +arr[i];
                }

            }


        }

                        
       
        
    }
};
int main()
{
    
  
    
   
    cout << "1" << endl;
    class StudentName s4;
    s4.replace(1, -1);
    s4.print();
    cout << endl; 

    cout << "2" << endl;
    class StudentName s2;
    s2.replace(3, 2);
    s2.print();
    cout << endl;

    cout << "3" << endl;
    class StudentName s3;
    s3.replace(1, 1);
    s3.print();
    cout << endl;
    
    cout << "4" << endl;
    class StudentName s1;
    s1.replace(1, 2);
    s1.print();
    cout << endl;
    

   
}
