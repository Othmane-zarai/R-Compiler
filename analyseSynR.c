//Grammar Definition With New Values In The LEXER Read Read.me
/*

STMTS -> STMT STMTS
STMTS -> ''

STMT -> AFFEC
STMT -> IF
STMT -> WHILE
STMT -> FOR
STMT -> REPEAT
STMT -> BREAK
STMT -> NEXT
STMT -> PRINT
STMT -> ABS
STMT -> SIGN
STMT -> SQRT
STMT -> FLOOR
STMT -> CEILING
STMT -> EXPO
STMT -> LOG2
STMT -> LOG10
STMT -> COS
STMT -> SIN
STMT -> TAN
STMT -> ASIN
STMT -> ACOS
STMT -> ATAN
STMT -> COSH
STMT -> SINH
STMT -> TANH
STMT -> ACOSH
STMT -> ASINH
STMT -> ATANH
STMT -> MOD
STMT -> LENGHT
STMT -> CLASS
STMT -> OLDCLASS
STMT -> SUM
STMT -> MEAN
STMT -> MEDIAN
STMT -> QUANTILE
STMT -> RANK
STMT -> VAR
STMT -> SD
STMT -> MAX
STMT -> MIN
STMT -> ROUND
STMT -> SIGNIF
STMT -> PLOT

    AFFEC-> id SG_AFFEC B

    B-> FUNCT
    B-> VECTOR
    B-> id K

    B -> ABS
    B -> SIGN
    B -> SQRT
    B -> FLOOR
    B -> CEILING
    B -> EXPO
    B -> LOG2
    B -> LOG10
    B -> COS
    B -> SIN
    B -> TAN
    B -> ASIN
    B -> ACOS
    B -> ATAN
    B -> COSH
    B -> SINH
    B -> TANH
    B -> ACOSH
    B -> ASINH
    B -> ATANH
    B -> MOD
    B -> LENGHT
    B -> CLASS
    B -> OLDCLASS
    B -> SUM
    B -> MEAN
    B -> MEDIAN
    B -> QUANTILE
    B -> RANK
    B -> VAR
    B -> SD
    B -> MAX
    B -> MIN
    B -> ROUND
    B -> SIGNIF



    B -> ( EXP ) MULT1 MULT_AUX
    B -> num MULT1 MULT_AUX

    K -> ( ARGLIST )
    K -> MULT1 ADD1

    SG_AFFEC -> <-
    SG_AFFEC -> <<-
    SG_AFFEC -> =

    IF -> if ( OR ) { STMTS } ELSE
    ELSE -> ''
    ELSE -> else D
    D -> { STMTS }
    D -> IF

    FOR -> for ( id in   C
    C -> VECTOR ) { STMTS }
    C -> SEQ ) { STMTS }


    WHILE  -> while ( OR ) { STMTS }


    REPEAT -> repeat { STMTS }


    SWITCH -> switch ( VAL , VAL , ARGLIST )

    FUNCT ->  function ( ARGLIST ) { STMTS FUNCT_FIN
    FUNCT_FIN ->  return ( VAL ) }
    FUNCT_FIN -> }


        ARGLIST -> VAL ARGLIST1

        ARGLIST1 -> , VAL ARGLIST1
        ARGLIST1 -> ''

          VAL -> id
          VAL -> num
          VAL -> ''
          VAL -> AP_TOKEN id AP_TOKEN
          VAL -> GUILL_TOKEN id GUILL_TOKEN

          SEQ -> seq ( num , num , num )
          SEQ -> num : num

          VECTOR -> c ( ARGLIST )


            EXP -> MULT ADD1

            ADD1 -> + MULT ADD1
            ADD1 -> - MULT ADD1
            ADD1 -> ''

            MULT -> MULT_AUX MULT1
            MULT1 -> * MULT_AUX MULT1
            MULT1 -> / MULT_AUX MULT1
            MULT1 -> ''

            MULT_AUX -> ( EXP )
            MULT_AUX -> VAL

            OR -> AND OR1

            OR1 -> | AND OR1
            OR1 -> ''

            AND -> NOT AND1

            AND1 -> & NOT AND1
            AND1 -> ''

            NOT -> ! NOT
            NOT ->  COND

            COND -> ( AUX
            COND -> num MULT1 ADD1 COMP EXP
            COND -> TRUE
            COND -> FALSE
            COND -> id MULT1 ADD1 COMP EXP

            AUX -> EXP ) MULT1 ADD1 COMP EXP

            COMP -> <
            COMP -> >
            COMP -> <=
            COMP -> >=
            COMP -> ==
            COMP -> ''





BREAK -> BREAK_TOKEN
NEXT -> NEXT_TOKEN

PRINT -> print ( PRINT1 )
PRINT1 -> EXP
PRINT1 -> AP_TOKEN EXP AP_TOKEN
PRINT1 -> GUILL_TOKEN EXP GUILL_TOKEN

ABS -> abs ( VAL )
SIGN -> signe ( VAL )
SQRT -> sqrt ( VAL )
FLOOR -> floor ( VAL )
CEILING -> ceiling  ( VAL )
EXPO -> exp ( VAL )
LOG2 -> log2 ( VAL )
LOG10 -> log10 ( VAL )
COS -> cos ( VAL )
SIN -> sin ( VAL )
TAN -> tan ( VAL )
ASIN -> asin ( VAL )
ACOS -> acos  ( VAL )
ATAN ->atan  ( VAL )
COSH -> cosh  ( VAL )
SINH -> sinh  ( VAL )
TANH -> tanh  ( VAL )
ACOSH -> acosh  ( VAL )
ASINH -> asinh  ( VAL )
ATANH -> atanh  ( VAL )
MOD -> mod ( VAL , VAL )
LENGHT -> lenght ( VID )
CLASS -> class  ( VAL )
OLDCLASS -> oldclass  ( VAL )
SUM -> sum ( VID )
MEAN -> mean ( VID )
MEDIAN -> median ( VID )
QUANTILE -> quantile ( VID )
RANK -> rank ( VAL )
VAR -> var ( VID )
SD -> sd ( VID )
MAX -> max ( VID )
MIN -> min ( VID )
ROUND -> round( VAL , VAL )
SIGNIF -> signif ( VAL , VAL )
PLOT -> plot ( VID , VID )
VID -> VECTOR
VID -> id
SELECTION -> id [ POS ]
POS -> num
POS -> SEQ
POQ -> VECTOR
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
FILE* file;
char car_cour, car_prec;
char *str_read, str_token[100];
void afficher_Token();
int lire_comm();
int isseparateur();
void lire_nombre();
void lire_mot();
void lire_fct();
void STMTS();
void STMT();
void AFFEC();
void IF();
void WHILE();
void FOR();
void REPEAT();
void B();
void SUITE();
void C();
void SEQ();
void VECTOR();
void ARGLIST();
void ARGLIST1();
void WHILE();
void FUNCT();
void FUNCT_FIN();
void FUNCT_USE();
void REPEAT();
void COND();
void VAL();
void BREAK();
void NEXT();
void PRINT();
void PRINT1();
void ABS();
void SIGN();
void SQRT();
void FLOOR();
void CEILING();
void EXPO();
void LOG2();
void LOG10();
void COS();
void SIN();
void TAN();
void ASIN();
void ACOS();
void ATAN();
void COSH();
void SINH();
void TANH();
void ACOSH();
void ASINH();
void ATANH();
void MOD();
void LENGTH();
void CLASS();
void OLDCLASS();
void SUM();
void MEAN();
void MEDIAN();
void QUANTILE();
void RANK();
void VAR();
void VAR();
void SD();
void MAX();
void MIN();
void ROUND();
void SIGNIF();
void PLOT();
void VID();
void SELECTION();
void POS();
void EXP();
//void Test_Symbole(CODE_TOKENS ct , Erreurs erreur);
typedef enum {
	ID_TOKEN , NUM_TOKEN, VECTOR_TOKEN,SEQ_STR_TOKEN,
  //Condition tokens
  IF_TOKEN , ELSE_TOKEN,
  //loop tokens
  REPEAT_TOKEN , WHILE_TOKEN , SWITCH_TOKEN, FOR_TOKEN,
  //function token
  FUNCTION_TOKEN, RETURN_TOKEN, FUNCT_USE_TOKEN,
  NEXT_TOKEN , BREAK_TOKEN ,  TRUE_TOKEN , FALSE_TOKEN,
  NULL_TOKEN , INF1_TOKEN , IN_TOKEN,
  // Not available Tokens
  NAN_TOKEN , NA_TOKEN , NA_INTEGER_TOKEN , NA_REAL_TOKEN , NA_COMPLEX_TOKEN , NA_CHARACTER_TOKEN ,
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
  //Index=$ [[]], sequence token , Pr?dicteur lin?aire
  INDEX_TOKEN ,CRO_TOKEN,CRF_TOKEN ,SEQ_TOKEN, PR_LIN_TOKEN,
  	//Predifined functions
	PRINT_TOKEN , ABS_TOKEN , SIGN_TOKEN , SQRT_TOKEN , FLOOR_TOKEN , CEILING_TOKEN , EXPO_TOKEN ,
	LOG2_TOKEN , LOG10_TOKEN , COS_TOKEN , SIN_TOKEN , TAN_TOKEN , ASIN_TOKEN , ACOS_TOKEN , ATAN_TOKEN ,
	COSH_TOKEN , SINH_TOKEN , TANH_TOKEN , ACOSH_TOKEN , ASINH_TOKEN , ATANH_TOKEN ,MOD_TOKEN , LENGTH_TOKEN ,
	CLASS_TOKEN , OLDCLASS_TOKEN , SUM_TOKEN , MEAN_TOKEN , MEDIAN_TOKEN , QUANTILE_TOKEN , RANK_TOKEN , VAR_TOKEN ,
	SD_TOKEN , MAX_TOKEN , MIN_TOKEN , ROUND_TOKEN , SIGNIF_TOKEN , PLOT_TOKEN ,

  //Fin de fichier
  EOF_TOKEN,
  //Erreurs
  ERREUR_TOKEN
} CODES_TOKENS ;
CODES_TOKENS TSym_Cour;
typedef enum {
    STMT_SYN_ERR, AFF_SYN_ERR , IF_SYN_ERR, WHILE_SYN_ERR , FOR_SYN_ERR, REPEAT_SYN_ERR,
	SEQ_SYN_ERR, VECTOR_SYN_ERR , ARGLIST_SYN_ERR, FUNCT_SYN_ERR, FUNCT_USE_SYN_ERR,
	FUNCT_FIN_ERR, COND_SYN_ERR, VAL_SYN_ERR,
	//Syntax succes
	SYN_SUCC
}Syn_ERR;
Syn_ERR syn_err=SYN_SUCC;
typedef enum {
	ID_ERR , NUM_ERR, VECTOR_ERR,
  //Condition tokens
  IF_ERR , ELSE_ERR,
  //loop tokens
  REPEAT_ERR , WHILE_ERR , SWITCH_ERR, FOR_ERR,
  //function token
  FUNCTION_ERR, RETURN_ERR,
  NEXT_ERR , BREAK_ERR ,  TRUE_ERR , FALSE_ERR ,
  NULL_ERR , INF1_ERR , IN_ERR,
  // Not available Tokens
  NAN_ERR , NA_ERR , NA_INTEGER_ERR , NA_CHARACTER_ERR ,
  // Arithmetic tokens
  PLUS_ERR , MOINS_ERR , MULT_ERR , DIV_ERR , INFIX_ERR , PUISS_ERR,
  //Relational tokens
  SUP_ERR , SUPEG_ERR , INF_ERR , INFEG_ERR , EG_ERR , DIFF_ERR,
  //Logical tokens
  NON_ERR , AND_ERR , OR_ERR,
  //Affectation token
  AFF_ERR,
  //Seprator tokens
  PO_ERR , PF_ERR , ACCO_ERR , ACCF_ERR , VIR_ERR, PV_ERR,PT_ERR,AP_ERR,GUILL_ERR,
  //Index=$ [[]], sequence token , Pr?dicteur lin?aire
  INDEX_ERR ,CRO_ERR,CRF_ERR ,SEQ_ERR, PR_LIN_ERR,
  	PRINT_ERR , ABS_ERR , SIGN_ERR , SQRT_ERR , FLOOR_ERR , CEILING_ERR , EXPO_ERR ,
	LOG2_ERR , LOG10_ERR , COS_ERR , SIN_ERR , TAN_ERR , ASIN_ERR , ACOS_ERR , ATAN_ERR ,
	COSH_ERR , SINH_ERR , TANH_ERR , ACOSH_ERR , ASINH_ERR , ATANH_ERR ,MOD_ERR , LENGTH_ERR ,
	CLASS_ERR, OLDCLASS_ERR , SUM_ERR , MEAN_ERR , MEDIAN_ERR , QUANTILE_ERR , RANK_ERR , VAR_ERR ,
	SD_ERR , MAX_ERR , MIN_ERR , ROUND_ERR , SIGNIF_ERR , PLOT_ERR
  }Erreurs;
Erreurs TSym_Err;
char *Sym_Names[] = {
	"ID_TOKEN" , "NUM_TOKEN","VECTOR_TOKEN", "SEQ_STR_TOKEN",
  "IF_TOKEN" , "ELSE_TOKEN",
  "REPEAT_TOKEN" , "WHILE_TOKEN" , "SWITCH_TOKEN", "FOR_TOKEN",
  "FUNCTION_TOKEN", "RETURN_TOKEN","FUNCT_USE",
  "NEXT_TOKEN" , "BREAK_TOKEN" , "TRUE_TOKEN" , "FALSE_TOKEN" ,
  "NULL_TOKEN" , "INF1_TOKEN" ,"IN_TOKEN",
  "NAN_TOKEN" , "NA_TOKEN" , "NA_INTEGER_TOKEN" , "NA_REAL_TOKEN" , "NA_COMPLEX_TOKEN" , "NA_CHARACTER_TOKEN" ,
  "PLUS_TOKEN" , "MOINS_TOKEN" ,"MULT_TOKEN" ,"DIV_TOKEN" ,"INFIX_TOKEN" ,"PUISS_TOKEN",
  "SUP_TOKEN" ,"SUPEG_TOKEN" ,"INF_TOKEN" ,"INFEG_TOKEN" ,"EG_TOKEN" ,"DIFF_TOKEN",
  "NON_TOKEN" ,"AND_TOKEN" ,"OR_TOKEN",
  "AFF_TOKEN",
  "PO_TOKEN" ,"PF_TOKEN" ,"ACCO_TOKEN" ,"ACCF_TOKEN" , "VIR_TOKEN" , "PV_TOKEN" , "PT_TOKEN",/*"PR_LIN_TOKEN",*/"AP_TOKEN","GUILL_TOKEN",
  "INDEX_TOKEN" ,"CRO_TOKEN","CRF_TOKEN","SEQ_TOKEN" ,"PRINT_TOKEN","ABS_TOKEN","SIGN_TOKEN","SQRT_TOKEN","FLOOR_TOKEN","CEILING_TOKEN","EXPO_TOKEN","LOG2_TOKEN","LOG10_TOKEN",
	"COS_TOKEN","SIN_TOKEN","TAN_TOKEN","ACOS_TOKEN","ASIN_TOKEN","ATAN_TOKEN","COSH_TOKEN","SINH_TOKEN","TANH_TOKEN","ACOSH_TOKEN","ASINH_TOKEN","ATANH_TOKEN","MOD_TOKEN",
	"LENGTH_TOKEN","CLASS_TOKEN","OLDCLASS_TOKEN","SUM_TOKEN","MEAN_TOKEN","MEDIAN_TOKEN","QUANTILE_TOKEN","RANK_TOKEN","VAR_TOKEN","SD_TOKEN","MAX_TOKEN","MIN_TOKEN","ROUND_TOKEN","SIGN_TOKEN","PLOT_TOKEN"
  ,"EOF_TOKEN"
};

char *Sym_ErreurNames[] = {
	"ID_ERR" ,"NUM_ERR",
  "IF_ERR" , "ELSE_ERR",
  "REPEAT_ERR" , "WHILE_ERR" ,"SWITCH_ERR","FOR_ERR",
  "FUNCTION_ERR", "RETURN_ERR",
  "NEXT_ERR" ,"BREAK_ERR" , "TRUE_ERR" ,"FALSE_ERR" ,
  "NULL_ERR" , "INF1_ERR" , "IN_ERR",
  "NAN_ERR" ,"NA_ERR" ,"NA_INTEGER_ERR" ,"NA_REAL_ERR" ,"NA_COMPLEX_ERR" ,"NA_CHARACTER_ERR" ,
  "PLUS_ERR" ,"MOINS_ERR" ,"MULT_ERR","DIV_ERR" ,"INFIX_ERR" ,"PUISS_ERR",
  "SUP_ERR" ,"SUPEG_ERR" ,"INF_ERR" ,"INFEG_ERR" ,"EG_ERR" , "DIFF_ERR",
  "NON_ERR" ,"AND_ERR","OR_ERR","AFF_ERR",
  "PO_ERR","PF_ERR" ,"ACCO_ERR" ,"ACCF_ERR" ,"VIR_ERR","PV_ERR,PT_ERR",
  "INDEX_ERR","CRO_ERR","CRF_ERR" ,"SEQ_ERR","PR_LIN_ERR"
  "PRINT_ERR","ABS_ERR","SIGN_ERR","SQRT_ERR","FLOOR_ERR","CEILING_ERR","EXPO_ERR","LOG2_ERR","LOG10_ERR",
	"COS_ERR","SIN_ERR","TAN_ERR","ACOS_ERR","ASIN_ERR","ATAN_ERR","COSH_ERR","SINH_ERR","TANH_ERR","ACOSH_ERR","ASINH_ERR","ATANH_ERR","MOD_ERR",
	"LENGTH_ERR","CLASS_ERR","OLDCLASS_ERR","SUM_ERR","MEAN_ERR","MEDIAN_ERR","QUANTILE_ERR","RANK_ERR","VAR_ERR","SD_ERR","MAX_ERR","MIN_ERR","ROUND_ERR","SIGN_ERR","PLOT_ERR"
};
char *Syn_ERRNames[]={
    "STMT_SYN_ERR", "AFF_SYN_ERR" , "IF_SYN_ERR", "WHILE_SYN_ERR" ,"FOR_SYN_ERR","REPEAT_SYN_ERR",
	"SEQ_SYN_ERR","VECTOR_SYN_ERR" ,"ARGLIST_SYN_ERR","FUNCT_SYN_ERR","FUNCT_USE_SYN_ERR",
	"FUNCT_FIN_ERR", "COND_SYN_ERR", "VAL_SYN_ERR",
	"SYN_SUCC"
};

void afficher_Token(){
  if(TSym_Cour != ERREUR_TOKEN)
    { printf("%s \n",Sym_Names[TSym_Cour]);}
  else printf("%s \n",Sym_ErreurNames[TSym_Err]);
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
/*void lire_fct(){
  car_cour = fgetc(file);
  while(car_cour != ')'){
    if(isalpha(car_cour)){
      lire_mot();
    }
    if(isdigit(car_cour)){
      lire_nombre();
    }
  }
}
*/

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
    TSym_Cour = NUM_TOKEN;
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
  else if(!(strcasecmp(str_token,"Inf"))) TSym_Cour = INF1_TOKEN;
  else if(!(strcasecmp(str_token,"NaN"))) TSym_Cour = NAN_TOKEN;
  else if(!(strcasecmp(str_token,"NA"))) TSym_Cour = NA_TOKEN;
  else if(!(strcasecmp(str_token,"NA_integer"))) TSym_Cour = NA_INTEGER_TOKEN;
  else if(!(strcasecmp(str_token,"NA_real"))) TSym_Cour = NA_REAL_TOKEN;
  else if(!(strcasecmp(str_token,"NA_complex"))) TSym_Cour = NA_COMPLEX_TOKEN;
  else if(!(strcasecmp(str_token,"NA_character"))) TSym_Cour = NA_CHARACTER_TOKEN;
  else if(!(strcasecmp(str_token,"seq"))) TSym_Cour = SEQ_STR_TOKEN ;
  else if(!(strcasecmp(str_token,"c"))) TSym_Cour = VECTOR_TOKEN;
  else if(!(strcasecmp(str_token,"return"))) TSym_Cour = RETURN_TOKEN;

  else if(!(strcasecmp(str_token,"print"))) TSym_Cour = PRINT_TOKEN;
	else if(!(strcasecmp(str_token,"abs"))) TSym_Cour = ABS_TOKEN;
	else if(!(strcasecmp(str_token,"signe"))) TSym_Cour = SIGN_TOKEN;
	else if(!(strcasecmp(str_token,"sqrt"))) TSym_Cour = SQRT_TOKEN;
	else if(!(strcasecmp(str_token,"floor"))) TSym_Cour = FLOOR_TOKEN;
	else if(!(strcasecmp(str_token,"ceiling"))) TSym_Cour = CEILING_TOKEN;
	else if(!(strcasecmp(str_token,"exp"))) TSym_Cour = EXPO_TOKEN;
	else if(!(strcasecmp(str_token,"log2"))) TSym_Cour = LOG2_TOKEN;
	else if(!(strcasecmp(str_token,"log10"))) TSym_Cour = LOG10_TOKEN;
	else if(!(strcasecmp(str_token,"cos"))) TSym_Cour = COS_TOKEN;
	else if(!(strcasecmp(str_token,"sin"))) TSym_Cour = SIN_TOKEN;
	else if(!(strcasecmp(str_token,"tan"))) TSym_Cour = TAN_TOKEN;
	else if(!(strcasecmp(str_token,"asin"))) TSym_Cour = ASIN_TOKEN;
	else if(!(strcasecmp(str_token,"acos"))) TSym_Cour = ACOS_TOKEN;
	else if(!(strcasecmp(str_token,"atan"))) TSym_Cour = ATAN_TOKEN;
	else if(!(strcasecmp(str_token,"cosh"))) TSym_Cour = COSH_TOKEN;
	else if(!(strcasecmp(str_token,"sinh"))) TSym_Cour = SINH_TOKEN;
	else if(!(strcasecmp(str_token,"tanh"))) TSym_Cour = TANH_TOKEN;
	else if(!(strcasecmp(str_token,"acosh"))) TSym_Cour = ACOSH_TOKEN;
	else if(!(strcasecmp(str_token,"asinh"))) TSym_Cour = ASINH_TOKEN;
	else if(!(strcasecmp(str_token,"atanh"))) TSym_Cour = ATANH_TOKEN;

	else if(!(strcasecmp(str_token,"mod"))) TSym_Cour = MOD_TOKEN;
	else if(!(strcasecmp(str_token,"length"))) TSym_Cour = LENGTH_TOKEN;
	else if(!(strcasecmp(str_token,"class"))) TSym_Cour = CLASS_TOKEN;
	else if(!(strcasecmp(str_token,"oldclass"))) TSym_Cour = OLDCLASS_TOKEN;
	else if(!(strcasecmp(str_token,"sum"))) TSym_Cour = SUM_TOKEN;
	else if(!(strcasecmp(str_token,"mean"))) TSym_Cour = MEAN_TOKEN;
	else if(!(strcasecmp(str_token,"median"))) TSym_Cour = MEDIAN_TOKEN;
	else if(!(strcasecmp(str_token,"quantile"))) TSym_Cour = QUANTILE_TOKEN;
	else if(!(strcasecmp(str_token,"rank"))) TSym_Cour = RANK_TOKEN;
	else if(!(strcasecmp(str_token,"var"))) TSym_Cour = VAR_TOKEN;
	else if(!(strcasecmp(str_token,"sd"))) TSym_Cour = SD_TOKEN;
	else if(!(strcasecmp(str_token,"max"))) TSym_Cour = MAX_TOKEN;
	else if(!(strcasecmp(str_token,"min"))) TSym_Cour = MIN_TOKEN;
	else if(!(strcasecmp(str_token,"round"))) TSym_Cour = ROUND_TOKEN;
	else if(!(strcasecmp(str_token,"signif"))) TSym_Cour = SIGNIF_TOKEN;
	else if(!(strcasecmp(str_token,"plot"))) TSym_Cour = PLOT_TOKEN;

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

void Test_Symbole(CODES_TOKENS cl,Erreurs err){
  if(TSym_Cour==cl && syn_err==SYN_SUCC){
    sym_suiv();
  }
  else{
    printf("%s \n",Sym_ErreurNames[err]);
	printf("Erreur de syntaxe %s \n",Syn_ERRNames[syn_err]);
  }
}
void STMTS(){//STMTS : STMT STMTS | $
  if(TSym_Cour != ID_TOKEN && TSym_Cour != IF_TOKEN && TSym_Cour != WHILE_TOKEN && TSym_Cour != FOR_TOKEN && TSym_Cour !=SWITCH_TOKEN && TSym_Cour != REPEAT_TOKEN && TSym_Cour != FUNCTION_TOKEN){
  	sym_suiv();
  }
  else {
    STMT();
  	STMTS();
  }
}
void STMT(){//STMT : AFFEC | IF | WHILE | FOR | REPEAT  | FUNCT
    switch (TSym_Cour){
    	case ID_TOKEN : AFFEC(); break;
    	case IF_TOKEN : IF(); break;
    	case WHILE_TOKEN : WHILE(); break;
    	case FOR_TOKEN : FOR(); break;
    	case REPEAT_TOKEN : REPEAT(); break;
    	case BREAK_TOKEN : BREAK(); break;
    	case NEXT_TOKEN : NEXT(); break;
    	case PRINT_TOKEN : PRINT(); break;
    	case ABS_TOKEN : ABS(); break;
		case SIGN_TOKEN : SIGN(); break;
		case SQRT_TOKEN : SQRT(); break;
		case FLOOR_TOKEN : FLOOR(); break;
		case CEILING_TOKEN : CEILING(); break;
		case EXPO_TOKEN : EXPO(); break;
		case LOG2_TOKEN : LOG2(); break;
		case LOG10_TOKEN : LOG10(); break;
		case COS_TOKEN : COS(); break;
		case SIN_TOKEN : SIN(); break;
		case TAN_TOKEN : TAN(); break;
		case ASIN_TOKEN : ASIN(); break;
		case ACOS_TOKEN : ACOS(); break;
		case ATAN_TOKEN : ATAN(); break;
		case COSH_TOKEN : COSH(); break;
		case SINH_TOKEN : SINH(); break;
		case TANH_TOKEN : TANH(); break;
		case ACOSH_TOKEN : ACOSH(); break;
		case ASINH_TOKEN : ASINH(); break;
		case ATANH_TOKEN : ATANH(); break;
		case LENGTH_TOKEN : LENGTH(); break;
		case CLASS_TOKEN : CLASS(); break;
		case OLDCLASS_TOKEN : OLDCLASS(); break;
		case SUM_TOKEN : SUM(); break;
		case MEAN_TOKEN : MEAN(); break;
		case MEDIAN_TOKEN : MEDIAN(); break;
		case QUANTILE_TOKEN : QUANTILE(); break;
		case RANK_TOKEN : RANK(); break;
		case VAR_TOKEN : VAR(); break;
		case SD_TOKEN : SD(); break;
		case MAX_TOKEN : MAX(); break;
		case MIN_TOKEN : MIN(); break;
		case ROUND_TOKEN : ROUND(); break;
		case SIGNIF_TOKEN : SIGNIF(); break;
		case PLOT_TOKEN : PLOT(); break;
		default : syn_err = STMT_SYN_ERR; break;
	}
}
void AFFEC(){//AFFEC: ?id?  SG_AFFEC TEST
      Test_Symbole(ID_TOKEN,ID_ERR);
     Test_Symbole(AFF_TOKEN,AFF_ERR);
     B();

 }

void B(){//EXPR | FUNCT | FUNCT_USE | OBJECT | VECTOR | VAL
    switch (TSym_Cour){
    	case ID_TOKEN :  break;
    	case NUM_TOKEN : break;
    	case NA_TOKEN : break;
    	case FUNCTION_TOKEN : FUNCT(); break;
    	case VECTOR_TOKEN : VECTOR(); break;
    	case ABS_TOKEN : ABS(); break;
		case SIGN_TOKEN : SIGN(); break;
		case SQRT_TOKEN : SQRT(); break;
		case FLOOR_TOKEN : FLOOR(); break;
		case CEILING_TOKEN : CEILING(); break;
		case EXPO_TOKEN : EXPO(); break;
		case LOG2_TOKEN : LOG2(); break;
		case LOG10_TOKEN : LOG10(); break;
		case COS_TOKEN : COS(); break;
		case SIN_TOKEN : SIN(); break;
		case TAN_TOKEN : TAN(); break;
		case ASIN_TOKEN : ASIN(); break;
		case ACOS_TOKEN : ACOS(); break;
		case ATAN_TOKEN : ATAN(); break;
		case COSH_TOKEN : COSH(); break;
		case SINH_TOKEN : SINH(); break;
		case TANH_TOKEN : TANH(); break;
		case ACOSH_TOKEN : ACOSH(); break;
		case ASINH_TOKEN : ASINH(); break;
		case ATANH_TOKEN : ATANH(); break;
		case LENGTH_TOKEN : LENGTH(); break;
		case CLASS_TOKEN : CLASS(); break;
		case OLDCLASS_TOKEN : OLDCLASS(); break;
		case SUM_TOKEN : SUM(); break;
		case MEAN_TOKEN : MEAN(); break;
		case MEDIAN_TOKEN : MEDIAN(); break;
		case QUANTILE_TOKEN : QUANTILE(); break;
		case RANK_TOKEN : RANK(); break;
		case VAR_TOKEN : VAR(); break;
		case SD_TOKEN : SD(); break;
		case MAX_TOKEN : MAX(); break;
		case MIN_TOKEN : MIN(); break;
		case ROUND_TOKEN : ROUND(); break;
		case SIGNIF_TOKEN : SIGNIF(); break;
		case PLOT_TOKEN : PLOT(); break;
    	default : syn_err = AFF_SYN_ERR;break;
	}
}
void IF(){ //IF  : ?if? ?(?  COND  ?)? SUITE IF_ELSE_IF IF_ELSE
     Test_Symbole(IF_TOKEN,IF_ERR);
     SUITE();
     if(TSym_Cour==ELSE_TOKEN){
     	sym_suiv();
     	if(TSym_Cour==IF_TOKEN)
     	{
           SUITE();
		}
		else {
          Test_Symbole(ACCO_TOKEN,ACCO_ERR);
            STMTS();
        Test_Symbole(ACCF_TOKEN,ACCF_ERR);
		}
	 }
}
void SUITE(){
	Test_Symbole(PO_TOKEN,PO_ERR);
    COND();
    Test_Symbole(PF_TOKEN,PF_ERR);
    Test_Symbole(ACCO_TOKEN,ACCO_ERR);
    STMTS();
    Test_Symbole(ACCF_TOKEN,ACCF_ERR);
}
void FOR(){ // FOR : ?for? ?(?  ?id?  ?in?   INTERVALE  ? )? SUITE
    Test_Symbole(FOR_TOKEN,FOR_ERR);
    Test_Symbole(PO_TOKEN,PO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(IN_TOKEN,IN_ERR);
    C();

}
void C(){
   switch(TSym_Cour){
   	case VECTOR_TOKEN : VECTOR();break;
   	case SEQ_STR_TOKEN : SEQ();break;
   	case NUM_TOKEN : Test_Symbole(SEQ_TOKEN,SEQ_ERR);Test_Symbole(NUM_TOKEN,NUM_ERR);break;
   	//Erreur looping default
   	default : syn_err = FOR_SYN_ERR;break;
   }
   Test_Symbole(PF_TOKEN,PF_TOKEN);
   Test_Symbole(ACCO_TOKEN,ACCO_ERR);
   STMTS();
   Test_Symbole(ACCF_TOKEN,ACCF_ERR);
}
void SEQ(){
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(NUM_TOKEN,NUM_ERR);
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	Test_Symbole(NUM_TOKEN,NUM_ERR);
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	Test_Symbole(NUM_TOKEN,NUM_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void VECTOR(){//VECTOR : 'c' '(' EXPR  VCT  ?)?
	Test_Symbole(PO_TOKEN,PO_ERR);
    ARGLIST();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void ARGLIST(){
	//sym_suiv();
	if(TSym_Cour==PF_TOKEN){}
	else {
         VAL();
	     if(TSym_Cour==VIR_TOKEN){
		 VAL(); ARGLIST1();
	    }
	    else syn_err = ARGLIST_SYN_ERR;
	   }
}
void ARGLIST1(){
	sym_suiv();
	if(TSym_Cour==PF_TOKEN){}
	else {
         VAL();
	     if(TSym_Cour==VIR_TOKEN){
		 VAL(); ARGLIST1();}
		 else syn_err = ARGLIST_SYN_ERR;
	}
}
void WHILE(){ // WHILE  : ?while? ?(? COND ?)? SUITE
  Test_Symbole(WHILE_TOKEN,WHILE_ERR);
  Test_Symbole(PO_TOKEN,PO_ERR);
  COND();//COND ::= EXPR [= | <> | < | > | <= | >=] EXPR
  Test_Symbole(PF_TOKEN,PF_ERR);
  Test_Symbole(ACCO_TOKEN,ACCO_ERR);
  STMTS();
  Test_Symbole(ACCF_TOKEN,ACCF_ERR);
}
void FUNCT(){//FUNCT :  'function' '('  ARGLIST  ')' '{' STMTS  FUNCT_FIN
     Test_Symbole(FUNCTION_TOKEN,FUNCTION_ERR);
     Test_Symbole(PO_TOKEN,PO_ERR);
     ARGLIST();
     Test_Symbole(PF_TOKEN,PF_ERR);
     Test_Symbole(ACCO_TOKEN,ACCO_ERR);
     STMTS();
     FUNCT_FIN();//FUNCT_FIN : 'return' '(' VAL ')' '}' | '}
}
void FUNCT_FIN(){
	//sym_suiv();
	switch(TSym_Cour){
	    case ACCF_TOKEN : sym_suiv(); break;
	    case RETURN_TOKEN : sym_suiv();
		                    Test_Symbole(PO_TOKEN,PO_ERR);
		                    VAL();
		                    Test_Symbole(PF_TOKEN,PF_ERR);
		                    Test_Symbole(ACCF_TOKEN,ACCF_ERR);
		                    break;
	    default : syn_err = FUNCT_SYN_ERR; break;
	}
}
void FUNCT_USE(){// FUNCT_USE : 'id'  '(' ARGLIST ')'
        Test_Symbole(ID_TOKEN,ID_ERR);
        Test_Symbole(PO_TOKEN,PO_ERR);
        ARGLIST();
        Test_Symbole(PF_TOKEN,PF_ERR);
}
void REPEAT(){//REPEAT  : ?repeat? SUITE
   Test_Symbole(REPEAT_TOKEN,REPEAT_ERR);
   Test_Symbole(ACCO_TOKEN,ACCO_ERR);
   STMTS();
   Test_Symbole(ACCF_TOKEN,ACCF_ERR);
}
void COND(){
	Test_Symbole(ID_TOKEN,ID_ERR);
}
void VAL(){//'id' | 'num ' | 'NA' |'NA_complex_'|'NA_REAL_'| 'NA_integer_'|'NA_charachter_'
    sym_suiv();
    switch(TSym_Cour){
    	case ID_TOKEN :sym_suiv();
    	               break;
    	case NUM_TOKEN : sym_suiv();
    	                break;
    	case NA_TOKEN : sym_suiv();
    	                break;
    	case NA_COMPLEX_TOKEN : sym_suiv();
    	                break;
    	case NA_REAL_TOKEN : sym_suiv();
    	                break;
    	case NA_INTEGER_TOKEN :sym_suiv();
    	                break;
    	default :  syn_err=VAL_SYN_ERR;break;
}
}
void BREAK(){
	Test_Symbole(BREAK_TOKEN,BREAK_ERR);
}
void NEXT(){
	Test_Symbole(NEXT_TOKEN,NEXT_ERR);
}
void PRINT(){
	Test_Symbole(PRINT_TOKEN,PRINT_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	PRINT1();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void PRINT1(){
	switch (TSym_Cour){
		case PO_TOKEN : EXP();break;
		case ID_TOKEN : EXP();break;
		case AP_TOKEN : EXP();Test_Symbole(AP_TOKEN,AP_ERR);break;
		case GUILL_TOKEN : EXP();Test_Symbole(GUILL_TOKEN,GUILL_ERR);break;
		case NUM_TOKEN : sym_suiv();break;
	}
}
void ABS(){
	Test_Symbole(ABS_TOKEN,ABS_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void SIGN(){
	Test_Symbole(SIGN_TOKEN,SIGN_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void SQRT(){
	Test_Symbole(SQRT_TOKEN,SQRT_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void FLOOR(){
	Test_Symbole(FLOOR_TOKEN,FLOOR_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void CEILING(){
	Test_Symbole(CEILING_TOKEN,CEILING_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void EXPO(){
	Test_Symbole(EXPO_TOKEN,EXPO_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void LOG2(){
	Test_Symbole(LOG2_TOKEN,LOG2_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void LOG10(){
	Test_Symbole(LOG10_TOKEN,LOG10_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void COS(){
	Test_Symbole(COS_TOKEN,COS_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void SIN(){
	Test_Symbole(SIN_TOKEN,SIN_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void TAN(){
	Test_Symbole(TAN_TOKEN,TAN_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void ASIN(){
	Test_Symbole(ASIN_TOKEN,ASIN_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void ACOS(){
	Test_Symbole(ACOS_TOKEN,ACOS_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void ATAN(){
	Test_Symbole(ATAN_TOKEN,ATAN_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void COSH(){
	Test_Symbole(COSH_TOKEN,COSH_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void SINH(){
	Test_Symbole(SINH_TOKEN,SINH_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void TANH(){
	Test_Symbole(TANH_TOKEN,TANH_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void ACOSH(){
	Test_Symbole(ACOSH_TOKEN,ACOSH_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void ASINH(){
	Test_Symbole(ASINH_TOKEN,ASINH_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void ATANH(){
	Test_Symbole(ATANH_TOKEN,ATANH_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void MOD(){
	Test_Symbole(MOD_TOKEN,MOD_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void LENGTH(){
	Test_Symbole(LENGTH_TOKEN,LENGTH_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void CLASS(){
	Test_Symbole(CLASS_TOKEN,CLASS_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void OLDCLASS(){
	Test_Symbole(OLDCLASS_TOKEN,OLDCLASS_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void SUM(){
	Test_Symbole(SUM_TOKEN,SUM_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void MEAN(){
	Test_Symbole(MEAN_TOKEN,MEAN_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void MEDIAN(){
	Test_Symbole(MEDIAN_TOKEN,MEDIAN_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void QUANTILE(){
	Test_Symbole(QUANTILE_TOKEN,QUANTILE_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void RANK(){
	Test_Symbole(RANK_TOKEN,RANK_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void VAR(){
	Test_Symbole(VAR_TOKEN,VAR_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void SD(){
	Test_Symbole(SD_TOKEN,SD_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void MAX(){
	Test_Symbole(MAX_TOKEN,MAX_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void MIN(){
	Test_Symbole(MIN_TOKEN,MIN_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void ROUND(){
	Test_Symbole(ROUND_TOKEN,ROUND_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void SIGNIF(){
	Test_Symbole(SIGNIF_TOKEN,SIGNIF_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VAL();
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	VAL();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void PLOT(){
	Test_Symbole(PLOT_TOKEN,PLOT_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	VID();
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	VID();
	Test_Symbole(PF_TOKEN,PF_ERR);
}
void VID(){
	switch(TSym_Cour){
		case VECTOR_TOKEN : VECTOR();break;
		case ID_TOKEN : break;
	}
}
void SELECTION(){
	Test_Symbole(ID_TOKEN,ID_ERR);
	POS();
}
void POS(){
	switch(TSym_Cour){
		case NUM_TOKEN : break;
		case SEQ_TOKEN : break;
		case VECTOR_TOKEN : break;
	}
}
void EXP(){
	Test_Symbole(ID_TOKEN,ID_ERR);
}
int main(int argc, char *argv[]) {
	file = fopen("/Users/othmane zarai/Desktop/test_R.txt","r+");
	car_cour = fgetc(file);
	  //sym_suiv();
	while(car_cour != EOF)
	{
		sym_suiv();
		//STMTS();
	}
	if(car_cour==EOF){
	printf("Votre code est syntaxiquement correcte \n");
	printf("EOF_TOKEN");}
    return 0;
}
