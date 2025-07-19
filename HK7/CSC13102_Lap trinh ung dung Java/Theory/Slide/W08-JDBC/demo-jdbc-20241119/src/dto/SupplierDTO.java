package dto;

public class SupplierDTO {
    int supID;
    String supName;
    String street;
    String city;
    String state;
    String zip;

    public SupplierDTO() {
        this.supID = 0;
        this.supName = "";
        this.street = "";
        this.city = "";
        this.state = "";
        this.zip = "";
    }

    public SupplierDTO(int supID, String supName, String street, String city, String state, String zip) {
        this.supID = supID;
        this.supName = supName;
        this.street = street;
        this.city = city;
        this.state = state;
        this.zip = zip;
    }

    public int getSupID() {
        return supID;
    }

    public void setSupID(int supID) {
        this.supID = supID;
    }

    public String getSupName() {
        return supName;
    }

    public void setSupName(String supName) {
        this.supName = supName;
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getZip() {
        return zip;
    }

    public void setZip(String zip) {
        this.zip = zip;
    }

    public String toString() {
        return supID + " - " + supName + " - " + street + " - " + city + " - " + state + " - " + zip;
    }
}