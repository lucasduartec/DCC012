
#include "common.h"

#include <fstream>
#include <sstream>

/* Mostra a ajuda */
void show_help(char *name) {
    std::cerr << " [uso] " << name << "<opcoes>" << std::endl
              << "     -h            mostra ajuda e sai. " << std::endl
              << "     -i <string>   string a ser comprimida" << std::endl 
              << "     -f filename   filename a ser comprimido" << std::endl;
        exit(-1) ;
}

std::string read_file(char* fname)
{
    std::ifstream fin(fname);
    if(fin.is_open())
    {
        return std::string((std::istreambuf_iterator<char>(fin)),
                     (std::istreambuf_iterator<char>()));
    }
    return "";
}


/* Retorna a string de entrada */
// usa a função getopt do C para filtrar comandos
// por linha de alrgumento.
std::string getInputString(int argc, char **argv) {
    int opt;
    

    if(argc < 2) {
        show_help(argv[0]);
    }

    while ((opt = getopt(argc, argv, "hi:f:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            show_help(argv[0]);
            break;
        case 'i':
            return std::string(optarg);
            break;
        case 'f':
            return read_file(optarg);
            break;
        default:
            show_help(argv[0]);
            break;
        }
    }
    
    return "";
}
