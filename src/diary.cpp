#include "diary.h"

Diary::Diary(const std::string& filename): filename(filename), max(10), size(0), messages(nullptr){
        messages = new Message[max];
        loadMessage();
}
Diary::~Diary(){
        write();
        delete[] messages;
}
void Diary::realoc()
{
    if (size >= max) {
        Message *temp;
        temp = new Message[max*2];
        for (int i = 0; i < max; ++i)
        {
            temp[i] = messages[i];
        }
        delete[] messages;
        messages = new Message[max*2];
        
        for (int i = 0; i < max; ++i)
        {
            messages[i] = temp[i];
        }
        delete[] temp;
        max *= 2;
    }

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
    realoc();
    Message m;
    m.date = mdate;
    m.time = mtime;
    m.content = message;
    messages[size] = m;
    size++;

}



void Diary::write(){
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
	
void Diary::list(){
	for(int i =0 ; i < size; i++){
		std::cout << messages[i].content << std::endl;
	}
}


Message* Diary::search(std::string what){
    for(int i =0 ; i < size; i++){
        if(messages[i].content.find(what) != std::string::npos){
            std::cout << messages[i].content << std::endl;
            return &messages[i];
        }
    }
    return NULL;
}
