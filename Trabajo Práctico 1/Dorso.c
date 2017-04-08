 /** \brief valida si los numeros son positivos
  * \param el numero a validar
  * \return si el numero validado es positivo
  *
  */

int validarPositivo(int x)
{
    int esValido=0;
    if (x>0)
    {
        esValido=1;
    }
    return esValido;
}

/** \brief valida si los numeros se encuentran dentro de un rango
 * \param x es el numero a validar
 * \param inf es el limite inferior para validar
 * \param sup es el limite superior para validar
 * \return si pertenece o no al rango el numero.
 *
 */

 int validarRangoInt(int x, int inf, int sup)
 {
    int esValido=0;
    if (x>=inf && x<=sup)
    {
        esValido= 1;
    }
 return esValido;
 }

 /** \brief Suma los valores ingresados
 * \param x es el primer numero a sumar
 * \param y es el segundo numero a sumar
 * \return el resultado de la suma.
 *
 */

 float suma(float x,float y)
 {
     float resultado;
     resultado=x+y;
     return resultado;

 }

  /** \brief resta los valores ingresados
 * \param x es el primer numero a restar
 * \param y es el segundo numero a restar
 * \return el resultado de la resta.
 *
 */

 float resta(float x,float y)
 {
     float resultado;
     resultado=x-y;
     return resultado;

 }

  /** \brief Divide los valores ingresados
 * \param x es el numero a dividir
 * \param y es el numero por el cual se divide
 * \return el resultado de la division.
 *
 */

 float division(float x,float y)
 {
     float resultado;
     resultado=x/y;
     return resultado;

 }
  /** \brief Multiplica los valores ingresados
 * \param x es el numero a multiplicar
 * \param y es el numero por el cual se multiplica
 * \return el resultado de la multiplicacion.
 *
 */

 float multiplicacion(float x,float y)
 {
     float resultado;
     resultado=x*y;
     return resultado;

 }
/** \brief Calcula el factorial, mediante la recursividad
 * \param x es el numero ingresado por el usuario
 * \return primero se retorna ella misma, para generar la recursividad, luego retorna el resultado del factorial.
 *
 */


float factorial(int x)
{
    float resultado;
    if(x==0)
    {
    resultado = 1;
    }
    else{


    resultado=x* factorial(x-1);
    }
    return (resultado);
}
