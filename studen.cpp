#include <iostream>
#include <list>

class Student{
    private string name;
    private list course;
    private string campus;
    private string email;

    public Student(String name, String course, String campus, String email) {
        this.name = name;
        this.course.add(course);
        this.campus = campus;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCampus() {
        return campus;
    }

    public void setCampus(String campus) {
        this.campus = campus;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public List <String> getCourse() {
        return course;
    }

    public void setCourse(List <String> course) {
        this.course = course;
    }
}