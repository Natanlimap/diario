#include "diary.h"

Diary::Diary(const std::string& filename): filename(filename), max(10), size(0), messages(0)
{
        getConfig();
        loadMessage();
}
Diary::~Diary()
{
    if(size > 0){
        write();
    }
}


void Diary::getConfig()
{
    std::ifstream file; //arquivo 
    std::string line; // linha a ser lida
    file.open("diary.config");

    getline(file, line);
    filename = line.substr(5);

    getline(file, line);
    format = line.substr(16);
  
}

void Diary::loadMessage()
{
    std::ifstream file; //arquivo 
    std::string line; // linha a ser lida
    file.open(filename); // nome do arquivo aberto
    Date mdate;
    Time mtime;

    //arquvio nao existe
    if(!(file.is_open())){
        return;
    }

    //Imprimindo o arquivo inteiro
    while(getline(file, line)){
        if(line.front() == '#'){
            mdate.set_from_string(line.substr(2, line.size()));
        }else if((line.front() == '-')){
            mtime.set_from_string(line.substr(2, 9));
            line = line.substr(11, line.size());
            add(line, mdate, mtime);

        }
    }

    //fecharemos o arquivo
    file.close(); 

}


void Diary::add(const std::string& message, Date mdate, Time mtime)
{
    
    Message m;
    m.date = mdate;
    m.time = mtime;
    m.content = message;
    messages.push_back(m);
    size++;

}



void Diary::write()
{
    std::ofstream file;
    Date currentDate = messages[0].date;
    file.open(filename);

    //escrevendo a mensagem
    if(!file.is_open()){
        std::cout << "Arquivo inexistente ou inacessivel" << std::endl;
        return;
    }

    file << "# "<< messages[0].date.to_string() << std::endl;

    for (int i = 0; i < size; ++i)
    {
        if(currentDate.to_string() != messages[i].date.to_string()){
            currentDate = messages[i].date;
            file << "# "<< messages[i].date.to_string() << std::endl;

        }
        file << "- "<< messages[i].time.to_string()<< " " << messages[i].content << std::endl;

    }

    file.close();
}
	
void Diary::list()
{
 

	for(int i =0 ; i < size; i++){
        for(int j = 0; j < format.size(); j++){
            if(format[j] == '%'){
                
                switch(format[j+1]){
                    case 'd':
                        std::cout << messages[i].date.to_string();
                        j= j+2;
                        break;

                    case 't':
                        std::cout << messages[i].time.to_string();
                        j= j+2;
                        break;

                    case 'm':
                        std::cout << messages[i].content;
                        j= j+2;
                        break;
                    default:
                    std::cout << "%";
                }

            }
            std::cout << format[j];
        }
        std::cout << std::endl;

	}
}


std::vector<Message> Diary::search(std::string what)
{

    std::vector<Message> temp;
    for(int i =0 ; i < size; i++){
        if(messages[i].content.find(what) != std::string::npos){
            temp.push_back(messages[i]);
        }
    }
    return temp;
}
