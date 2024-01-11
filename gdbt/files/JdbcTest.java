
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class JdbcTest {

    public static void main(String[] args) throws SQLException, ClassNotFoundException {

        // JDBC driver laden:
        Class.forName("com.ibm.db2.jcc.DB2Driver");
        System.out.println("**** Loaded the JDBC driver ****");

        String url = "jdbc:db2:gdbt";

        // Nu maken we een verbinding met de gdbt database zonder dat de gebruikersnaam
        // en het paswoord moet ingegeven worden.
        // Als je dit op de Spooky server uitvoert, dan zal achterliggend jouw
        // account-naam gebruikt worden om in te loggen.
        Connection con = DriverManager.getConnection(url);

        PreparedStatement s = con.prepareStatement("select * from person");

        ResultSet rs = s.executeQuery();

        System.out.println("Results:");
        while (rs.next()) {
            int id = rs.getInt("id");
            String name = rs.getString("name");

            System.out.println("" + id + ", " + name);
        }
    }
}
