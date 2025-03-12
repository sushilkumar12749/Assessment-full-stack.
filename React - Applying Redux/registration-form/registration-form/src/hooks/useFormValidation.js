import { useState } from "react";

// Regular Expressions for Validation
const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
const usernameRegex = /^.{1,4}$/; // Max 4 characters
const passwordRegex = /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{6,}$/; // Min 6 chars, letters & numbers
const phoneRegex = /^[0-9]{10}$/; // 10-digit phone number

const useFormValidation = () => {
  const [errors, setErrors] = useState({});

  // Validate Function
  const validate = (name, value) => {
    let error = "";

    switch (name) {
      case "username":
        if (!usernameRegex.test(value)) error = "Username must be 1 to 4 characters.";
        break;
      case "email":
        if (!emailRegex.test(value)) error = "Invalid email format.";
        break;
      case "password":
        if (!passwordRegex.test(value)) error = "Password must be 6+ chars & include a number.";
        break;
      case "repeatPassword":
        error = "Passwords do not match.";
        break;
      case "phone":
        if (!phoneRegex.test(value)) error = "Invalid phone number (10 digits).";
        break;
      default:
        break;
    }

    setErrors((prevErrors) => ({ ...prevErrors, [name]: error }));
  };

  return { errors, validate };
};

export default useFormValidation;
