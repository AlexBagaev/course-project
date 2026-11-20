package passsystem;

public class Checkpoint {

  private String checkpointName;
  private Pass currentPass;
  private AccessRules rules;
  private boolean scanRez;

  public Checkpoint(String checkpointName, String rulesName, int zoneAccessLevel, Pass currentPass) {
    this.rules = new AccessRules(rulesName, zoneAccessLevel);
    this.checkpointName = checkpointName;
    this.currentPass = currentPass;
  }

  public void scanPass() {
    boolean check1 = rules.checkPassValid(currentPass.getValidPass());
    boolean check2 = rules.checkPassValid(currentPass.getValidPass());
    scanRez = check1 && check2;
  }

  public String printScanRez() {
    return (scanRez ? "Проход разрешён." : "Проход запрещён.");
  }
}
