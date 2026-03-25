#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/ElectricField.h"


TransformedView tv;
ElectricField ef;
float ec;

void Setup(AlxWindow* w){
    ef = ElectricField_New(100,100);
    tv = TransformedView_Make(
        (Vec2){ GetWidth(),GetHeight() },
        (Vec2){ -50.0f,0.0f },
        (Vec2){ 0.01f,0.01f },
        (float)GetWidth() / (float)GetHeight()
    );
    ec = 0.0f;
}
void Update(AlxWindow* w){
    TransformedView_HandlePanZoom(&tv,w->Strokes,GetMouse());
    const Vec2 m = TransformedView_ScreenWorldPos(&tv,GetMouse());

    if(Stroke(ALX_KEY_UP).DOWN){
        ec += 1.0f * w->ElapsedTime;
    }
    if(Stroke(ALX_KEY_DOWN).DOWN){
        ec -= 1.0f * w->ElapsedTime;
    }

    if(Stroke(ALX_MOUSE_L).PRESSED){
        ElectricField_AddCharge(&ef,(ElectricCharge){
            .pos = m,
            .ec = ec
        });
        ElectricField_Calc(&ef);
    }
    if(Stroke(ALX_MOUSE_R).PRESSED){
        ElectricField_RemoveCharge(&ef,m);
        ElectricField_Calc(&ef);
    }
    
    if(Stroke(ALX_KEY_R).PRESSED){
        ElectricField_AddObject(&ef,(ElectricObject){
            .p = m,
            .v = (Vec2){ 0.0f,0.0f },
            .ec = 1.0f
        });
    }
    
    ElectricField_Update(&ef,w->ElapsedTime);

    Clear(BLACK);
    
    ElectricField_Render(&ef,WINDOW_STD_ARGS,&tv,1.0f,WHITE);

    CStr_RenderAlxFontf(WINDOW_STD_ARGS,GetAlxFont(),0.0f,0.0f,BLUE,"C: %f",ec);
}
void Delete(AlxWindow* w){
    ElectricField_Free(&ef);
}

int main() {
    if(Create("Electric Field",1900,1000,1,1,Setup,Update,Delete)){
        Start();
    }
    return 0;
}
