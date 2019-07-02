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
    }

    void show(){
        cout << endl;
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

    ///////////////////////////////////////
    ////////////// UP E DOWN //////////////
    ///////////////////////////////////////

    // int cont_char(){
    //     auto pos = this->cursor;
    //     int cont = 0;
    //     while(*pos != '\n' && pos != this->texto.begin()){
    //         cont++;
    //         pos--;
    //     }
    //     if(cont != 1)
    //         return cont - 1;
    //     return cont;
    // }

    // list<char>::iterator find_break_line(bool side, list<char>::iterator pos){
    //     if(side){
    //         if(pos == this->texto.begin())
    //             return pos;
    //         if(*pos == '\n')
    //             pos--;
    //         while(*pos != '\n' && pos != this->texto.begin())
    //             pos--;
    //         return --pos;
    //     }else{
    //         if(pos == this->texto.end())
    //             return pos;
    //         while(*pos != '\n' && pos != this->texto.end())
    //             pos++;
    //         return --pos;
    //     }
    // }

    // void move_cursor(int qtd, bool side){
    //     auto pos = this->cursor;
    //     pos = find_break_line(side, pos);
    //     if(side){
    //         if(pos == this->texto.begin()){
    //             this->cursor = pos;
    //             return;
    //         }
    //     }else{
    //         if(pos == this->texto.end()){
    //             this->cursor = pos;
    //             return;
    //         }
    //     }
    //     pos = find_break_line(side, pos);
    //     this->cursor = pos;
    //     for(int a = 0; (*this->cursor != '\n' && a < qtd && this->cursor != this->texto.end()); a++)
    //         this->cursor++;
    // }

    // void up(){
    //     bool line_break = false;
    //     if(*this->cursor == '\n')
    //         this->cursor--;
    //     for(auto a = this->cursor; a != this->texto.begin(); a--)
    //         if(*a == '\n'){
    //             line_break = true;
    //             break;
    //         }
    //     if(line_break){
    //         int cont = cont_char();
    //         //cout << cont << endl;
    //         move_cursor(cont, true);
    //     }else
    //         this->cursor = this->texto.begin();
    // }

    // void down(){
    //     bool line_break = false;
    //     for(auto a = this->cursor; a != this->texto.end(); a++)
    //         if(*a == '\n'){
    //             line_break = true;
    //             break;
    //         }
    //     if(line_break){
    //         int cont = cont_char();
    //         move_cursor(cont, false);
    //     }else
    //         this->cursor = this->texto.end();
    // }

    ///////////////////////////////////////
    //////////// FIM UP E DOWN ////////////
    ///////////////////////////////////////

};

struct Editor{
    list<Ambient> linha_temporal;
    list<Ambient>::iterator estado_atual;

    Editor(Ambient atual){
        this->linha_temporal.push_back(atual);
        this->estado_atual = this->linha_temporal.begin();
    }
};

int main(){
    Ambient* atual = new Ambient();
    string input;
    char cmd;

    Editor* editor = new Editor(*atual);

    while(true){
        getline(cin, input);
        stringstream ss(input);

        while(ss >> cmd){
            if(cmd == 'R'){
                atual->_insert('\n');
                editor->linha_temporal.push_back(*atual);
                editor->estado_atual++;
            }else if(cmd == 'B'){
                atual->backspace();
                editor->linha_temporal.push_back(*atual);
                editor->estado_atual++;
            }else if(cmd == 'D'){
                atual->_delete();
                editor->linha_temporal.push_back(*atual);
                editor->estado_atual++;
            }else if(cmd == '>'){
                atual->move_right();
            }else if(cmd == '<'){
                atual->move_left();
            }else if(cmd == 'Z'){
                if(editor->estado_atual != editor->linha_temporal.begin()){
                    editor->estado_atual--;
                    *atual = *editor->estado_atual;
                }
            }else if(cmd == 'Y'){
                list<Ambient>::iterator aux = editor->estado_atual;
                aux++;
                if(aux != editor->linha_temporal.end()){
                    editor->estado_atual++;
                    *atual = *editor->estado_atual;
                }
            }else if(cmd == 'A'){
                //atual->up();
            }else if(cmd == 'V'){
                //atual->down();
            }else{
                atual->_insert(cmd);
                editor->linha_temporal.push_back(*atual);
                editor->estado_atual++;
            }
        }
        atual->show();
        //cout << "Último ambiente: " << editor->estado_atual->texto.front() << endl;
    }
}