package bus;
import java.util.*;
import dao.*;
import dto.*;

public class SupplierBUS {
    public List<SupplierDTO> getAll(){
        SupplierDAO supplierDAO = new SupplierDAO();
        return supplierDAO.getAll();
    }
}
