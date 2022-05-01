public interface TableOperations {
    void open(String filePath);

    void close();

    void save();

    void saveAs(String filePath);

    void edit();

    void help();

    void exit();
}
