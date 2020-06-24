#include <iostream>
#include <string>

#include "../include/app.h"
#include "../include/message.h"

App::App(const std::string &filename): diary(filename) {

}

void App::add(){
	
}

void App::add(std::string message){
	//mensagem enviada pelo cliente
	std::string message;
	//A mensagem nao foi passada pela linha de comando
	if(argc == 2)
	{ 
		std::cout << "Digite a mensagem" << std::endl;
		//recebemos o input da mensagem do cliente
		getline(std::cin, message); 
		std::cout << "Mensagem Adicionada" << std::endl;
	}
	else{
		//neste caso, a mensagem  foi passada pelo cliente via terminal, receberemos ela aqui.
		message = argv[2]; 
	}
}

void App::list(){

	//arquvio nao existe
	if(!(diary.is_open())){
		std::cout << "Arquivo inexistente ou inacessivel" << std::endl;
		return 1;
	}
	//Imprimindo o arquivo inteiro
	while(getline(diary.file, line)){
		if((line.front() == '-')){
			std::cout << line << std::endl;
		}
	}
}

int App::showUsage(){
		std::cout << "Uso:" << std::endl << "./diary add" << std::endl << "./diary add <message>" << std::endl << "./diary list" << std::endl; //Mostra para o usuario a entrada correta para o programa.
		return 1;
}


int App::run(int argc, char* argv[]) {

   	if(argc == 1)
	{
		return showUsage();
	}else
	{
		return functions(argc, argv);
	}
}

