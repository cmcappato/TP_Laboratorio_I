/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
 int getInt();

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat();

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar();

/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar);

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumerico(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char *str);

/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un char al usuario y lo valida si es f o m
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param input Array donde se cargar� el texto ingresado
 * \return El caracter ingresado por el usuario
 *
 */
char getValidSexo( char requestMessage[], char* input);

/**
 * \brief Solicita un texto al usuario, valiando espacios y numeros y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */
int getStringLetrasYNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario con espacios y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getStringConEspacio(char mensaje[],char input[]);

/**
 * \brief Valida el array para no tomar el ultimo barra n
 * \param lista Array con la cadena a ser analizada
 * \param tamanio es el tama�o del  Array
 *
 */
void arreglarCadena(char lista[], int tamanio);

/**
 * \brief Solicita un texto al usuario, valiando espacios y numeros mas extricto
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
  * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */
void getSuperAlfaNumerico(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Solicita un texto al usuario, devolviendo  espacios y letras
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
  * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */
int getStringValidNombre(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario, valiando espacios y letras unicamente mas extricto
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
  * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */
void getValidStringEspaciosYLetras(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Solicita un texto al usuario, valiando numeros y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */
int getNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un string al usuario, valiando unicamente numeros mas extricto
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el string ingresado
 * \return -
 */
void getValidStringNumeros(char requestMessage[],char errorMessage[], char input[]);

/**
 * \brief Solicita un texto al usuario, valiando puntos y numeros, y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */
int getNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un string al usuario, valiando unicamente numeros y puntos para hacer numeros decimales
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el string ingresado
 * \return -
 */
void getValidStringNumerosFlotantes(char requestMessage[],char errorMessage[], char input[]);
