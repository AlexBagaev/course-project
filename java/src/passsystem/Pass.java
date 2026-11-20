package passsystem;

public class Pass {

  private String id;
  private int accessLevel;
  private boolean validPass;

  public Pass(String id, int accessLevel, boolean validPass) {
    this.id = id;
    this.accessLevel = accessLevel;
    this.validPass = validPass;
  }

  public String getId() { return id; }
  public int getAccessLevel() { return accessLevel; }
  public boolean getValidPass() { return validPass; }

  public void validatePass() {
    if (validPass) {
      System.out.printf("Пропуск %s уже активирован.\n", id);
    } else {
      validPass = true;
      System.out.printf("Пропуск %s был активирован.\n", id);
    }
  }

  public void invalidatePass() {
    if (validPass) {
      validPass = false;
      System.out.printf("Пропуск %s был успешно деактивирован.\n", id);
    } else {
      System.out.printf("Пропуск %s уже деактивирован.\n", id);
    }
    
  }

}
