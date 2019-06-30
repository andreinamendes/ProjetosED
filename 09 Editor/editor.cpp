#include <iostream>
#include <sstream>
#include <list>

using namespace std;

struct Ambient{
    list<char> texto;
    list<char>::iterator cursor;

    Ambient(){
        this->cursor = texto.begin();
    }

    void _insert(char texto){
        this->texto.insert(cursor, texto);
        this->cursor = this->cursor++;
    }

    void show(){
        //cout << endl;
        for(list<char>::iterator a = this->texto.begin(); a != this->texto.end(); a++){
            if(a == this->cursor)
                cout << '|';
            cout << (*a);
        }
        if(this->cursor == this->texto.end())
            cout << '|';
        cout << '\n';
    }

    void backspace(){
        if(this->cursor != this->texto.begin()){
            this->cursor--;
            this->cursor = this->texto.erase(this->cursor);
        }
    }

    void _delete(){
        if(this->cursor != this->texto.end()){
            auto vitima = this->cursor++;
            this->texto.erase(vitima);
        }
    }

    void move_right(){
        if(this->cursor != this->texto.end())
            this->cursor++;
    }

    void move_left(){
        if(this->cursor != this->texto.begin())
            this->cursor--;
    }

    int cont_char(){
        auto pos = this->cursor;
        int cont = 0;
        while(*pos != '\n' && pos != this->texto.begin()){
            cont++;
            pos--;
        }
        if(cont != 1)
            return cont - 1;
        return cont;
    }

    list<char>::iterator find_break_line(bool side, list<char>::iterator pos){
        if(side){
            if(pos == this->texto.begin())
                return pos;
            if(*pos == '\n')
                pos--;
            while(*pos != '\n' && pos != this->texto.begin())
                pos--;
            return --pos;
        }else{
            if(pos == this->texto.end())
                return pos;
            while(*pos != '\n' && pos != this->texto.end())
                pos++;
            return --pos;
        }
    }

    void move_cursor(int qtd, bool side){
        auto pos = this->cursor;
        pos = find_break_line(side, pos);
        if(side){
            if(pos == this->texto.begin()){
                this->cursor = pos;
                return;
            }
        }else{
            if(pos == this->texto.end()){
                this->cursor = pos;
                return;
            }
        }
        pos = find_break_line(side, pos);
        this->cursor = pos;
        for(int a = 0; (*this->cursor != '\n' && a < qtd && this->cursor != this->texto.end()); a++)
            this->cursor++;
    }

    void up(){
        bool line_break = false;
        if(*this->cursor == '\n')
            this->cursor--;
        for(auto a = this->cursor; a != this->texto.begin(); a--)
            if(*a == '\n'){
                line_break = true;
                break;
            }
        if(line_break){
            int cont = cont_char();
            //cout << cont << endl;
            move_cursor(cont, true);
        }else
            this->cursor = this->texto.begin();
    }

    void down(){
        bool line_break = false;
        for(auto a = this->cursor; a != this->texto.end(); a++)
            if(*a == '\n'){
                line_break = true;
                break;
            }
        if(line_break){
            int cont = cont_char();
            move_cursor(cont, false);
        }else
            this->cursor = this->texto.end();
    }

    // void undo(){
        
    // }

    // void redo(){
        
    // }

};

struct Editor{
    list<Ambient> linha_temporal;
    list<Ambient>::iterator estado_atual;
};

int main(){
    Ambient* editor = new Ambient();
    string input;
    char cmd;

    //while(true){
        getline(cin, input);
        stringstream ss(input);

        while(ss >> cmd){
            if(cmd == 'R'){
                editor->_insert('\n');
            }else if(cmd == 'B'){
                editor->backspace();
            }else if(cmd == 'D'){
                editor->_delete();
            }else if(cmd == '>'){
                editor->move_right();
            }else if(cmd == '<'){
                editor->move_left();
            }else if(cmd == 'Z'){
                //editor->redo();
            }else if(cmd == 'Y'){
                //editor->undo();
            }else if(cmd == 'A'){
                editor->up();
            }else if(cmd == 'V'){
                editor->down();
            }else{
                editor->_insert(cmd);
            }
        }
        editor->show();
    //}
}