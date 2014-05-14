//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Media.hpp>
#include <FMX.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMozaikaForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelLeft;
	TPanel *PanelMain;
	TGridLayout *GridTool;
	TRectangle *RectangleRed;
	TGradientAnimation *GradientAnimation1;
	TRectangle *RectangleGreen;
	TGradientAnimation *GradientAnimation2;
	TRectangle *RectangleBlue;
	TGradientAnimation *GradientAnimation3;
	TRectangle *RectangleYellow;
	TGradientAnimation *GradientAnimation4;
	TRectangle *RectangleBrown;
	TGradientAnimation *GradientAnimation5;
	TRectangle *RectangleBlack;
	TGradientAnimation *GradientAnimation6;
	TGridLayout *GridMozaika;
	TRectangle *Rectangle1;
	TRectangle *Rectangle2;
	TRectangle *Rectangle6;
	TRectangle *Rectangle7;
	TRectangle *Rectangle8;
	TRectangle *Rectangle9;
	TRectangle *Rectangle10;
	TRectangle *Rectangle11;
	TRectangle *Rectangle12;
	TRectangle *Rectangle13;
	TRectangle *Rectangle14;
	TRectangle *Rectangle15;
	TRectangle *Rectangle16;
	TRectangle *Rectangle17;
	TRectangle *Rectangle18;
	TRectangle *Rectangle19;
	TRectangle *Rectangle20;
	TRectangle *Rectangle21;
	TRectangle *Rectangle22;
	TRectangle *Rectangle23;
	TRectangle *Rectangle24;
	TRectangle *Rectangle25;
	TRectangle *Rectangle26;
	TRectangle *Rectangle27;
	TRectangle *Rectangle28;
	TRectangle *Rectangle29;
	TRectangle *Rectangle30;
	TRectangle *Rectangle31;
	TRectangle *Rectangle32;
	TRectangle *Rectangle33;
	TRectangle *Rectangle34;
	TRectangle *Rectangle35;
	TRectangle *Rectangle36;
	TRectangle *Rectangle37;
	TRectangle *Rectangle38;
	TRectangle *Rectangle39;
	TRectangle *Rectangle40;
	TRectangle *Rectangle41;
	TRectangle *Rectangle42;
	TRectangle *Rectangle43;
	TRectangle *Rectangle44;
	TRectangle *Rectangle45;
	TRectangle *Rectangle46;
	TRectangle *Rectangle47;
	TRectangle *Rectangle48;
	TRectangle *Rectangle49;
	TRectangle *Rectangle50;
	TRectangle *Rectangle51;
	TRectangle *Rectangle52;
	TRectangle *Rectangle53;
	TRectangle *Rectangle54;
	TRectangle *Rectangle55;
	TRectangle *Rectangle56;
	TRectangle *Rectangle57;
	TRectangle *Rectangle58;
	TRectangle *Rectangle59;
	TRectangle *Rectangle60;
	TRectangle *Rectangle61;
	TRectangle *Rectangle62;
	TRectangle *Rectangle63;
	TRectangle *Rectangle64;
	TRectangle *Rectangle65;
	TRectangle *Rectangle66;
	TRectangle *Rectangle67;
	TRectangle *Rectangle68;
	TRectangle *Rectangle69;
	TRectangle *Rectangle70;
	TRectangle *Rectangle71;
	TRectangle *Rectangle72;
	TRectangle *Rectangle73;
	TRectangle *Rectangle74;
	TRectangle *Rectangle75;
	TRectangle *Rectangle76;
	TRectangle *Rectangle77;
	TRectangle *Rectangle78;
	TRectangle *Rectangle79;
	TRectangle *Rectangle80;
	TPanel *PanelTop;
	TLabel *LabelMozaika;
	TRectangle *Rectangle3;
	TRectangle *Rectangle4;
	TRectangle *Rectangle5;
	TRectangle *RectangleWhite;
	TGradientAnimation *GradientAnimation7;
	TButton *ButtonSettings;
	TButton *Button2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall RectangleRedClick(TObject *Sender);
	void __fastcall Rectangle1Click(TObject *Sender);
	void __fastcall ButtonNewClick(TObject *Sender);
	void __fastcall ButtonSettingsClick(TObject *Sender);

private:	// User declarations
	TList *array;
        TShape *select;

public:		// User declarations
	__fastcall TMozaikaForm(TComponent* Owner);
        void BuildGrid();
};
//---------------------------------------------------------------------------
extern PACKAGE TMozaikaForm *MozaikaForm;
//---------------------------------------------------------------------------
#endif
