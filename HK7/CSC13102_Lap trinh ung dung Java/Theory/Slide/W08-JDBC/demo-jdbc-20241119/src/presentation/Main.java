package presentation;
import java.util.*;
import bus.*;
import dto.*;

public class Main {
    public static void main(String []args){
        SupplierBUS supplierBUS = new SupplierBUS();
        List<SupplierDTO> supplierDTOs = supplierBUS.getAll();
        for(SupplierDTO supplierDTO : supplierDTOs){
            System.out.println(supplierDTO.getSupID() + " " + supplierDTO.getSupName() + " " + supplierDTO.getStreet() + " " + supplierDTO.getCity() + " " + supplierDTO.getState() + " " + supplierDTO.getZip());
        }
    }
}
