#include "OpNoviceDetectorMessenger.hh"
#include "OpNoviceDetectorConstruction.hh"

OpNoviceDetectorMessenger::OpNoviceDetectorMessenger(OpNoviceDetectorConstruction* detector):
    fDet(detector)
{
    G4cout << "Detector messenger constructed" << G4endl;
    fChangeSize = new G4UIdirectory("/changeSize/");
    fChangeSize -> SetGuidance("Change size of WOM box");

    boxWidthCmd = new G4UIcmdWithADoubleAndUnit("/changeSize/boxWidthCmd", this);

    boxWidthCmd->SetGuidance("Set new width of the WOM box (in z)");
    boxWidthCmd->SetParameterName("SteelZ", false);
    boxWidthCmd->SetUnitCategory("Length");
    boxWidthCmd->SetRange("SteelZ>0. && SteelZ<1000");
    boxWidthCmd->SetDefaultValue(335.);
    boxWidthCmd->SetDefaultUnit("mm");
    boxWidthCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

}

OpNoviceDetectorMessenger::~OpNoviceDetectorMessenger()
{
    delete boxWidthCmd;
}

void OpNoviceDetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
    G4cout << "Command name is: " << command->GetCommandName() << "; Commande value is " << newValue << G4endl;
    if( command == boxWidthCmd )
       { fDet->SetBoxWidth(boxWidthCmd->GetNewDoubleValue(newValue)); }
}

