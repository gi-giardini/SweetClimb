void IC_Jump (float coord_X, float coord_Y){
    if(coord_Y<)
    {
        coord_X = coord_X + 0.15;
        coord_Y = coord_Y + 0.2;
    }
    else
    {
        coord_X = coord_X + 0.15;
        coord_Y = coord_Y - 0.2;
    }
}

void vilainDance (){
    glRotatef(180, 1, 0, 0);
}

void QuedaBrigadeiro(float x_brig, float y_brig)
{
    if(y_brig<)
    {
        x_brig = x_brig-0.4;
        y_brig = y_brig-0.44;
    }
    
}

void RotateBrigadeiro(float x_brig, float y_brig)
{
    glRotate(45,0,0,1);
    x_brig = x_brig+0.3;
}