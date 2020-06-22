#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>

//Funcoes para obter o dia e hora formatados
std::string format_current_date(const std::string& format)
{
	std::time_t time = std::time(nullptr);
	char result[1024];
	std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
	return std::string(result);
}

std::string get_current_date()
{
	return format_current_date("%d/%m/%Y");
}

std::string get_current_time()
{
	return format_current_date("%H:%M:%S");
}

//verifica se o dia de hoje existe no diario
bool dayExists(){
	std::ifstream file; //arquivo 
	std::string line; // linha a ser lida
	std::string today = get_current_date(); // linha a ser lida

	file.open("diary.MD");
	while( getline(file, line)){
		if(line == ("# " + today)){
			file.close(); 
			return true;
		}
	}
	file.close(); 
	return false;

}
//explica como usar o arquivo
int showUsage(){
		std::cout << "Uso:" << std::endl << "./diary add" << std::endl << "./diary add <message>" << std::endl << "./diary list" << std::endl; //Mostra para o usuario a entrada correta para o programa.
		return 1;
}

// retorna todas as mensagens do arquivo
int list(int argc, const char *argv[]){

	std::ifstream file; //arquivo 
	std::string line; // linha a ser lida
	file.open("diary.MD"); // nome do arquivo aberto
	
	//arquvio nao existe
	if(!(file.is_open())){
		std::cout << "Arquivo inexistente ou inacessivel" << std::endl;
		return 1;
	}
	
	//Imprimindo o arquivo inteiro
	while(getline(file, line)){
		if((line.front() == '-')){
			std::cout << line << std::endl;
		}
	}

	//fecharemos o arquivo
	file.close(); 

}

//escreve no diario
int writeDiary(std::string message){
	std::ofstream file;

	file.open("diary.MD", std::ios::app);
	
	//escrevendo a mensagem
	if(!file.is_open()){
		std::cout << "Arquivo inexistente ou inacessivel" << std::endl;
		return 1;
	}
	if(!dayExists()){
		std::string today = get_current_date(); // linha a ser lida
		file <<"# " << today << std::endl;
	}	
	std::string hour = get_current_time();
	file << "- " << hour << " " << message << std::endl;
	file.close();
	return 0;
}


int add(int argc, const char *argv[]){

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

	writeDiary(message);
	
}


int functions(int argc, const char *argv[]){
	
	//possui mais de 1 argumento e quer adicionar algo ao arquivo
	if(!strcmp(argv[1], "add")){
		return add(argc, argv);
	}

	//possui mais de 1 argumento e vamos ler o arquivo
	if(!strcmp(argv[1], "list")){
		return list(argc, argv);
	}

	return 1; // argv nao e compativel com nenhuma das funcoes que criamos
}

int main(int argc, char const *argv[]) //funcao que mostra a implementacao de como receber argumentos pelo terminal.
{
	//nao possui argumentos alem do nome do arquivo
	if(argc == 1)
	{
		return showUsage();
	}else
	{
		return functions(argc, argv);
	}
}