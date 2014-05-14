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
#include <Data.DbxSqlite.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
class TOptionForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *LabelName;
	TEdit *EditName;
	TListBox *ListBox;
	TButton *ButtonSave;
	TButton *Button2;
	TSQLConnection *SQLConnection;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	TList *_array;
public:		// User declarations
	__fastcall TOptionForm(TComponent* Owner);
        void setPicture(TList *array);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionForm *OptionForm;
//---------------------------------------------------------------------------
#endif
