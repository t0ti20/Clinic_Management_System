# Clinic Management System

The Clinic Management System is a simple C-based application designed to facilitate the management of patients and appointment slots in a clinic. It offers separate modes for administrators and users, ensuring streamlined processes for patient registration, appointment booking, and more.

![Screenshot 2023-08-13 091804](https://github.com/t0ti20/Clinic_Management_System/assets/61616031/539a5147-72cd-4d63-a782-168299c50dbc)

## Features

### Admin Mode

Upon entering the Admin Mode, the system will prompt for a password. The default password is `1234`. There are three attempts allowed; if these are exhausted, the system will close.

**Admin functionalities include:**
1. **Add New Patient Record**: Admins can enter a patient's basic information, including name, age, gender, and ID. Note: The ID must be unique.
2. **Edit Patient Record**: By entering the patient ID, admins can modify existing patient information.
3. **Reserve a Slot with the Doctor**: The system provides five default slots ranging from 2 pm to 5 pm. Admins can assign these slots to patients by entering the patient ID.
4. **Cancel Reservation**: Reservations can be cancelled by entering the patient's ID.

### User Mode

Users don't need a password to access their mode.

**User functionalities include:**
1. **View Patient Record**: Users can retrieve patient details by entering the patient's ID.
2. **View Today’s Reservations**: This feature displays all the day's reservations along with the corresponding patient IDs.

## Prerequisites

- C compiler (e.g., GCC)

## Compilation and Running

1. Clone the repository:
```bash
git clone https://github.com/t0ti20/Clinic_Management_System.git
```
2. Navigate to the directory:
```bash
cd Clinic_Management_System/Code
```
3. Compile the code:
```bash
gcc Test.c -o clinic_system
```
4. Run the system:
```bash
./clinic_system
```
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Authors
- [@Khaled El_Sayed](https://github.com/t0ti20)
