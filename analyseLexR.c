#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
FILE* file;
//car_cour ==> reading current caracter / car_prec ==> previous caracter used in comment function
char car_cour, car_prec;
// buffer for handling symb_suiv
char *str_read, str_token[100];
// Printing current Token
void afficher_Token();
//Passing comments
int lire_comm();
// Avoiding spaces /n ' ' ..
int isseparateur();
// read number-format Token
void lire_nombre();
// read Word format Token
void lire_mot();
//Definition Of Langage reserved words and Special words
typedef enum {
	ID_TOKEN , VAL_TOKEN,
  //Condition tokens
  IF_TOKEN , ELSE_TOKEN,
  //loop tokens
  REPEAT_TOKEN , WHILE_TOKEN , SWITCH_TOKEN, FOR_TOKEN,
  //function token
  FUNCTION_TOKEN,
  NEXT_TOKEN , BREAK_TOKEN ,  TRUE_TOKEN , FALSE_TOKEN,
  NULL_TOKEN , Inf_TOKEN , IN_TOKEN,
  // Not available Tokens
  NaN_TOKEN , NA_TOKEN , NA_integer_TOKEN , NA_real_TOKEN , NA_complex_TOKEN , NA_character_TOKEN ,
  // Arithmetic tokens
  PLUS_TOKEN , MOINS_TOKEN , MULT_TOKEN , DIV_TOKEN , INFIX_TOKEN , PUISS_TOKEN,
  //Relational tokens
  SUP_TOKEN , SUPEG_TOKEN , INF_TOKEN , INFEG_TOKEN , EG_TOKEN , DIFF_TOKEN,
  //Logical tokens
  NON_TOKEN , AND_TOKEN , OR_TOKEN,
  //Affectation token
  AFF_TOKEN,
  //Seprator tokens
  PO_TOKEN , PF_TOKEN , ACCO_TOKEN , ACCF_TOKEN , VIR_TOKEN, PV_TOKEN,PT_TOKEN,AP_TOKEN,GUILL_TOKEN,
  //Index=$ [[]], sequence token , Pr�dicteur lin�aire
  INDEX_TOKEN ,CRO_TOKEN,CRF_TOKEN ,SEQ_TOKEN, PR_LIN_TOKEN,
  //END OF FILE
  EOF_TOKEN,
  //Erreurs
  ERREUR_TOKEN
} CODES_TOKENS ;
CODES_TOKENS TSym_Cour;

typedef enum {
	ID_ERR , VAL_ERR,
  //Condition tokens
  IF_ERR , ELSE_ERR,
  //loop tokens
  REPEAT_ERR , WHILE_ERR , SWITCH_ERR, FOR_ERR,
  //function token
  FUNCTION_ERR,
  NEXT_ERR , BREAK_ERR ,  TRUE_ERR , FALSE_ERR ,
  NULL_ERR , Inf_ERR , IN_ERR,
  // Not available Tokens
  NaN_ERR , NA_ERR , NA_integer_ERR , NA_real_ERR , NA_complex_ERR , NA_character_ERR ,
  // Arithmetic tokens
  PLUS_ERR , MOINS_ERR , MULT_ERR , DIV_ERR , INFIX_ERR , PUISS_ERR,
  //Relational tokens
  SUP_ERR , SUPEG_ERR , INF_ERR , INFEG_ERR , EG_ERR , DIFF_ERR,
  //Logical tokens
  NON_ERR , AND_ERR , OR_ERR,
  //Affectation token
  AFF_ERR,
  //Seprator tokens
  PO_ERR , PF_ERR , ACCO_ERR , ACCF_ERR , VIR_ERR, PV_ERR,PT_ERR,
  //Index=$ [[]], sequence token , Pr�dicteur lin�aire
  INDEX_ERR ,CRO_ERR,CRF_ERR ,SEQ_ERR, PR_LIN_ERR,
  }Erreurs;
Erreurs TSym_Err;
//String list to convert ennum values to String values
char *Sym_Names[] = {
	"ID_TOKEN" , "VAL_TOKEN",
  "IF_TOKEN" , "ELSE_TOKEN",
  "REPEAT_TOKEN" , "WHILE_TOKEN" , "SWITCH_TOKEN", "FOR_TOKEN",
  "FUNCTION_TOKEN",
  "NEXT_TOKEN" , "BREAK_TOKEN" , "TRUE_TOKEN" , "FALSE_TOKEN" ,
  "NULL_TOKEN" , "Inf_TOKEN" ,"IN_TOKEN",
  "NaN_TOKEN" , "NA_TOKEN" , "NA_integer_TOKEN" , "NA_real_TOKEN" , "NA_complex_TOKEN" , "NA_character_TOKEN" ,
  "PLUS_TOKEN" , "MOINS_TOKEN" ,"MULT_TOKEN" ,"DIV_TOKEN" ,"INFIX_TOKEN" ,"PUISS_TOKEN",
  "SUP_TOKEN" ,"SUPEG_TOKEN" ,"INF_TOKEN" ,"INFEG_TOKEN" ,"EG_TOKEN" ,"DIFF_TOKEN",
  "NON_TOKEN" ,"AND_TOKEN" ,"OR_TOKEN",
  "AFF_TOKEN",
  "PO_TOKEN" ,"PF_TOKEN" ,"ACCO_TOKEN" ,"ACCF_TOKEN" , "VIR_TOKEN" , "PV_TOKEN" , "PT_TOKEN",/*"PR_LIN_TOKEN",*/"AP_TOKEN","GUILL_TOKEN",
  "INDEX_TOKEN" ,"CRO_TOKEN","CRF_TOKEN","SEQ_TOKEN","EOF_TOKEN"
};
//same here
char *Sym_ErreurNames[] = {
	"ID_ERR" ,"VAL_ERR",
  "IF_ERR" , "ELSE_ERR",
  "REPEAT_ERR" , "WHILE_ERR" ,"SWITCH_ERR","FOR_ERR",
  "FUNCTION_ERR",
  "NEXT_ERR" ,"BREAK_ERR" , "TRUE_ERR" ,"FALSE_ERR" ,
  "NULL_ERR" , "Inf_ERR" , "IN_ERR",
  "NaN_ERR" ,"NA_ERR" ,"NA_integer_ERR" ,"NA_real_ERR" ,"NA_complex_ERR" ,"NA_character_ERR" ,
  "PLUS_ERR" ,"MOINS_ERR" ,"MULT_ERR","DIV_ERR" ,"INFIX_ERR" ,"PUISS_ERR",
  "SUP_ERR" ,"SUPEG_ERR" ,"INF_ERR" ,"INFEG_ERR" ,"EG_ERR" , "DIFF_ERR",
  "NON_ERR" ,"AND_ERR","OR_ERR","AFF_ERR",
  "PO_ERR","PF_ERR" ,"ACCO_ERR" ,"ACCF_ERR" ,"VIR_ERR","PV_ERR,PT_ERR",
  "INDEX_ERR","CRO_ERR","CRF_ERR" ,"SEQ_ERR","PR_LIN_ERR",
};

void afficher_Token(){
  if(TSym_Cour != ERREUR_TOKEN)
    printf("%s \n",Sym_Names[TSym_Cour]);
  else
    printf("%s \n",Sym_ErreurNames[TSym_Err]);
}

int lire_comm(){
  car_prec= car_cour;
  car_cour = fgetc(file);
  while( (car_prec!='\n' ) && car_cour != EOF ){
      car_prec = car_cour;
      car_cour = fgetc(file);
  }
  if (car_cour == EOF) {TSym_Cour=EOF_TOKEN;}
  return 0;
}

int isseparateur(){
if( isspace(car_cour) || car_cour == '#' || car_cour=='\n' || car_cour=='\t' ){
    if(car_cour == '#' ) return lire_comm();
    else car_cour = fgetc(file);
    return 1;
  }
  return 0;
}


void lire_nombre(){
  while(isdigit(car_cour)){
    *str_read++ = car_cour;
    car_cour = fgetc(file);
  }
  *str_read = '\0';
  if(str_read - str_token > 11){
    //TSym_Cour = ERREUR_TOKEN;
    //TSym_Err = ERR_NUM_LONG;
    }
  else
    TSym_Cour = VAL_TOKEN;
}

void lire_mot(){
  while(isdigit(car_cour) || isalpha(car_cour)){
    *str_read++ = car_cour;
    car_cour = fgetc(file);
  }
  /*if(car_cour=='('){
     lire_fct();
  }*/
  *str_read = '\0';
  // "'"
  if(!(strcasecmp(str_token,"if"))) TSym_Cour = IF_TOKEN;
  else if(!(strcasecmp(str_token,"else"))) TSym_Cour = ELSE_TOKEN;
  else if(!(strcasecmp(str_token,"repeat"))) TSym_Cour = REPEAT_TOKEN;
  else if(!(strcasecmp(str_token,"while"))) TSym_Cour = WHILE_TOKEN;
  else if(!(strcasecmp(str_token,"switch"))) TSym_Cour = SWITCH_TOKEN;
  else if(!(strcasecmp(str_token,"function"))) TSym_Cour = FUNCTION_TOKEN;
  else if(!(strcasecmp(str_token,"for"))) TSym_Cour = FOR_TOKEN;
  else if(!(strcasecmp(str_token,"in"))) TSym_Cour = IN_TOKEN;
  else if(!(strcasecmp(str_token,"next"))) TSym_Cour = NEXT_TOKEN;
  else if(!(strcasecmp(str_token,"break"))) TSym_Cour = BREAK_TOKEN;
  else if(!(strcasecmp(str_token,"true"))) TSym_Cour = TRUE_TOKEN;
  else if(!(strcasecmp(str_token,"false"))) TSym_Cour = FALSE_TOKEN;
  else if(!(strcasecmp(str_token,"null"))) TSym_Cour = NULL_TOKEN;
  else if(!(strcasecmp(str_token,"Inf"))) TSym_Cour = Inf_TOKEN;
  else if(!(strcasecmp(str_token,"NaN"))) TSym_Cour = NaN_TOKEN;
  else if(!(strcasecmp(str_token,"NA"))) TSym_Cour = NA_TOKEN;
  else if(!(strcasecmp(str_token,"NA_integer"))) TSym_Cour = NA_integer_TOKEN;
  else if(!(strcasecmp(str_token,"NA_real"))) TSym_Cour = NA_real_TOKEN;
  else if(!(strcasecmp(str_token,"NA_complex"))) TSym_Cour = NA_complex_TOKEN;
  else if(!(strcasecmp(str_token,"NA_character"))) TSym_Cour = NA_character_TOKEN;
  else TSym_Cour = ID_TOKEN;
}

void sym_suiv(){
  str_read = str_token;
  while(isseparateur());

  if(isdigit(car_cour))lire_nombre();
  else {
    if(isalpha(car_cour))lire_mot();
    else {
      switch (car_cour){

        case ',' : TSym_Cour = VIR_TOKEN; break;
        case ';' : TSym_Cour = PV_TOKEN ; break;
        case '(' : TSym_Cour = PO_TOKEN; break;
        case ')' : TSym_Cour = PF_TOKEN ; break;
        case '{' : TSym_Cour = ACCO_TOKEN ; break;
        case '}' : TSym_Cour = ACCF_TOKEN ; break;
        case '=' : car_cour = fgetc(file);
                   if(car_cour=='='){ TSym_Cour=EG_TOKEN;}
                   else{TSym_Cour=AFF_TOKEN;}
                   break;
        case '+' : TSym_Cour = PLUS_TOKEN; break;
        case '-' : car_cour = fgetc(file);
                   if(car_cour=='>'){
				      car_cour = fgetc(file);
				      if(car_cour=='>'){TSym_Cour = AFF_TOKEN;}
				      else TSym_Cour = AFF_TOKEN;
				   }
				   else TSym_Cour = MOINS_TOKEN; break;
        case '*' : TSym_Cour = MULT_TOKEN; break;
        case '/' : TSym_Cour = DIV_TOKEN; break;
        case '.' : TSym_Cour = PT_TOKEN; break;

        case '>' : car_cour = fgetc(file);
                  if(car_cour == '=') TSym_Cour = SUPEG_TOKEN;
                  else TSym_Cour = SUP_TOKEN; break;
        case '<' : car_cour = fgetc(file);
                  if(car_cour == '=') TSym_Cour = INFEG_TOKEN;
                  else if (car_cour == '-') TSym_Cour =AFF_TOKEN;
                  else if (car_cour =='<'){
                  	car_cour = fgetc(file);
                  	if(car_cour=='-') {TSym_Cour=AFF_TOKEN;}
				  }
				  else TSym_Cour = INF_TOKEN; break;
        case '%' : car_cour = fgetc(file);
                   if(car_cour == '%'){TSym_Cour=INFIX_TOKEN;}
                   break;
        case '^' : TSym_Cour=PUISS_TOKEN; break;
        case '!' : car_cour = fgetc(file);
                   if(car_cour=='='){TSym_Cour=DIFF_TOKEN;}
                   else TSym_Cour=NON_TOKEN; break;
        case '&' : TSym_Cour=AND_TOKEN;break;
        case '|' : TSym_Cour = OR_TOKEN;break;
        //case '~' : TSym_Cour = PR_LIN_TOKEN ; break;
        case ':' : TSym_Cour = SEQ_TOKEN;break;
        case '$' : TSym_Cour = INDEX_TOKEN; break;
        case '[' : TSym_Cour = CRO_TOKEN ; break;
        case ']' : TSym_Cour = CRF_TOKEN ; break;
        case 39 : TSym_Cour = AP_TOKEN ; break;
        case 34 : TSym_Cour = GUILL_TOKEN ; break;
        case EOF : TSym_Cour = EOF_TOKEN; return;
        default : TSym_Cour = ERREUR_TOKEN; /*TSym_Err = ERR_CAR_INC*/;car_cour = fgetc(file);
      }
      if(TSym_Cour != ERREUR_TOKEN && TSym_Cour != INF_TOKEN && TSym_Cour != SUP_TOKEN && TSym_Cour != EOF_TOKEN)
        car_cour = fgetc(file);
    }
  }
  afficher_Token();
}
/*void Test_Symbole(CODE_TOKENS ct , Erreurs erreur){
	if(TSym_Cour==ct){
		sym_suiv();
	}
	else {
		printf("%s \n",Erreurs[erreur]);
	}
}
*/

int main() {
	char * path;
	printf("Set Path :\n");
	scanf("%s\n",path);
	file = fopen(path);
	car_cour = fgetc(file);
	while(car_cour != EOF)
	{
		sym_suiv();
	}
	printf("EOF_TOKEN");
  return 0;
}
