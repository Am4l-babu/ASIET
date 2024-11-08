import java.sql.*;

class main {

    public static void main(String[] args) {
        Connection con = null;
        PreparedStatement p = null;
        ResultSet rs = null;

        try {
            String url = "jdbc:mysql://localhost:3306/your_database_name";
            String user = "your_username";
            String password = "your_password";

            con = DriverManager.getConnection(url, user, password);

            String sql = "SELECT * FROM your_table_name";
            p = con.prepareStatement(sql);
            rs = p.executeQuery();

            System.out.println("id\t\tname\t\temail");

            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                String email = rs.getString("email");
                System.out.println(id + "\t\t" + name + "\t\t" + email);
            }
        } catch (SQLException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            try {
                if (rs != null) rs.close();
                if (p != null) p.close();
                if (con != null) con.close();
            } catch (SQLException e) {
                System.out.println("Error closing resources: " + e.getMessage());
            }
        }
    }
}
