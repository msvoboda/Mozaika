//---------------------------------------------------------------------------

#ifndef SettingsFormH
#define SettingsFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>

#include "MozaikaClass.h"
//---------------------------------------------------------------------------
class TOptionForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *LabelName;
	TEdit *EditName;
	TListBox *ListBox;
	TButton *ButtonSave;
	TButton *ButtonOpen;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DbmozaikaConnectionAfterConnect(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonOpenClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
	TList *_array;
        TList *_load_array;
public:		// User declarations
	__fastcall TOptionForm(TComponent* Owner);
        void setPicture(TList *array);
        void setTool(TList *load_array);
        void __fastcall Refresh();
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionForm *OptionForm;
//---------------------------------------------------------------------------
#endif
