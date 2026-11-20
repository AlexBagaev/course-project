import java.lang.ref.WeakReference;
import passsystem.*;

public class Program {

  public static void main(String[] args) {
    System.out.println("=== Демонстрация фрагмента сценария ===");
    System.out.println("=== Демонстрация работы ссылок ===");

    Pass pass1 = new Pass("L0004",4,false);
    Pass pass2 = pass1;
    pass2.validatePass();
    pass1.toString();

    Checkpoint kpp1 = new Checkpoint("kpp1","entry",4,pass1);
    kpp1.scanPass();

    System.out.println("=== Освобождение ресурсов без дестурктора ===");
    try (AccessLog log = new AccessLog("История входа")) {
      log.write(kpp1.printScanRez());
      System.out.println("Выход из try");
    }

    System.out.println("=== Демонстрация работы сборщика мусора ===");
    Pass temp = new Pass("T0000",0,false);
    WeakReference<Pass> watcher = new WeakReference<>(temp);

    System.out.println(watcher.get() != null);
    temp = null;
    System.gc();
    System.out.println(watcher.get() != null);
  }
}
