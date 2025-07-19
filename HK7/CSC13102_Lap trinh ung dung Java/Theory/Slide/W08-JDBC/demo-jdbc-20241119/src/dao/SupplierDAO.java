package dao;
import java.sql.*;
import java.util.*;
import dto.*;

public class SupplierDAO {
    public List<SupplierDTO> getAll() {
        List<SupplierDTO> list = new ArrayList<>();
        UtilityDAO utilityDAO = new UtilityDAO();
        Connection conn = utilityDAO.getConnection();
        if(conn == null) {
            return list;
        }
        String query =
      "select SUP_ID, SUP_NAME, STREET, CITY, STATE, ZIP from SUPPLIERS";
        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery(query);
            while (rs.next()) {
            int supplierID = rs.getInt("SUP_ID");
            String supplierName = rs.getString("SUP_NAME");
            String street = rs.getString("STREET");
            String city = rs.getString("CITY");
            String state = rs.getString("STATE");
            String zip = rs.getString("ZIP");
            SupplierDTO supplier = new SupplierDTO(supplierID, supplierName, street, city, state, zip);
            list.add(supplier);
        }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return list;
    }
}
