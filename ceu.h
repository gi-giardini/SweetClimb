//Função para definição das nuvens
void nuvens(float pontox, float pontoy){
    glPushMatrix();
        glColor3ub(230,230,230);
        glTranslatef(pontox, pontoy, -10);
        glutSolidSphere(1,20,20);
    glPopMatrix();

    glPushMatrix();
        glColor3ub(230,230,230);
        glTranslatef(pontox-0.5, pontoy-0.5, -10);
        glutSolidSphere(1,20,20);   
    glPopMatrix();

    glPushMatrix();
        glColor3ub(230,230,230);
        glTranslatef(pontox+0.5, pontoy-0.5, -10);
        glutSolidSphere(1,20,20);   
    glPopMatrix();

    glPushMatrix();
        glColor3ub(230,230,230);
        glTranslatef(pontox, pontoy-0.5, -10);
        glutSolidSphere(1,20,20);
    glPopMatrix();
}

void criar_nuvens(){
   //x positivo y positivo
   nuvens(3, 1);
   nuvens(12, 15);
   nuvens(9, 7);
   nuvens(5, 17);

   //x negativo y positivo
   nuvens(-2, 6);
   nuvens(-8, 5);
   nuvens(-3, 13);
   nuvens(-12, 17);
  
}