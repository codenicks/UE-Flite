#include "..\include\flite.h"
#include "..\include\cst_args.h"

#include <iostream>
#include "..\lang\usenglish\usenglish.h"
#include "..\lang\cmulex\cmu_lex.h"

#include <string>
#include <sstream>


cst_voice *register_cmu_us_rms(const char *voxdir);
void unregister_cmu_us_rms(cst_voice *v);


static void lookup_and_print(cst_lexicon *l, const char *word, const char *pos)
{
	cst_val *p;
	printf("Lookup: %s %s\n", word, pos);
	p = lex_lookup(l, word, pos, NULL);
	val_print(stdout, p);
	printf("\n");
	delete_val(p);
}






int main(int argc, char **argv)
{
	


	 cst_voice *v;
	flite_init();
	v = new_voice();
	cst_lexicon *lex;
	lex = cmu_lex_init();
	feat_set(v->features, "lexicon", lexicon_val(lex)); 

	cst_val *p;
	p = lex_lookup(lex, "Hi, how are you ? 2", "n", NULL);
	val_print2(p);
	



	/*
	cst_voice *v;
	cst_voice *v1;
	if (argc != 2)
	{
	fprintf(stderr, "usage: flite_test FILE\n");
	exit(-1);
	}

	flite_init();
	v1 = register_cmu_us_rms(NULL);
	flite_text_to_speech("FLITE is a great Talk to Speech library", v1, "play");
	*/


	//lookup_and_print(lex, "project", "n");
	//cst_fprintf(stdout, "%s", val_string(p));
	//std::stringstream stream;
	//auto * old = std::cout.rdbuf(stream.rdbuf());
	//val_print(stdout, p);
	//FILE * pFile;
	//pFile = fopen("file.txt", "w");
	//val_print(pFile, p);
	//delete_val(p);
	//const char *s;
	//int i;
	//val_generic(p, i, s);
	//s = (const char *)val_string(p);
	//printf("%c", *s);
	//char *string = "project";
	//char *s;

	
	//cst_fprintf2( "This is just one argument \n");
	
	//cst_fprintf2( "lol \n");
	
	//	s = (char*)malloc(strlen(string) + 1);
	//char *s2;
	//val_print2(stdout, p, s, s2);
	//std::cout.rdbuf(old);
	//std::string s = stream.str();
	//std::cout << s << '\n';
	//delete_val(p);

	//printf("text %s", *s2);
/*	FILE * pFile;
	pFile = fopen("file.txt", "w");
	cst_fprintf2(pFile, "This is just one argument %d \n");
	fclose(pFile);
	char text [20];
	char *s = &text;
	sprintf(text, "blabla");
	printf("%c", *s); */

	return 0;


}

