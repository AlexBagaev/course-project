package passsystem;

public class AccessRules {

  private int zoneAccessLevel;
  private String rulesName;

  public AccessRules (String rulesName, int zoneAccessLevel) {
    this.rulesName = rulesName;
    this.zoneAccessLevel = zoneAccessLevel;
    System.out.println("Создан объект класса AccessRules");
  }

  public boolean checkPassValid(boolean passValid) {
    if(passValid) {
      return true;
    } else {
      return false;
    }
  }

  public boolean compareAccessLevel(int passAccessLevel) {
    if (passAccessLevel == zoneAccessLevel) {
      return true;
    } else {
      return false;
    }
  } 
}