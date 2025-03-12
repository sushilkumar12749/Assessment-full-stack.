import React, { useState } from "react";
import { useDispatch } from "react-redux";
import { setFormData } from "../redux/formSlice";
import useFormValidation from "../hooks/useFormValidation";
import { Form, Button, Container, Row, Col, Alert } from "react-bootstrap";

const RegistrationForm = () => {
  const [formData, setFormDataState] = useState({
    username: "",
    email: "",
    password: "",
    repeatPassword: "",
    firstName: "",
    lastName: "",
    phone: "",
    address: "",
    town: "",
    region: "",
    zip: "",
    country: "",
  });

  const dispatch = useDispatch();
  const { errors, validate } = useFormValidation();
  const [submitted, setSubmitted] = useState(false);

  // Handle Input Change
  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormDataState({ ...formData, [name]: value });

    if (name === "repeatPassword" && value !== formData.password) {
      validate(name, value);
    } else {
      validate(name, value);
    }
  };

  // Handle Form Submission
  const handleSubmit = (e) => {
    e.preventDefault();
    if (!Object.values(errors).some((err) => err) && Object.values(formData).every((field) => field)) {
      dispatch(setFormData(formData));
      console.log("Form Data Submitted:", formData);
      setSubmitted(true);
    }
  };

  return (
    <Container>
      <h2 className="text-center mt-3">Registration Form</h2>
      {submitted && <Alert variant="success">Registration Successful!</Alert>}
      <Form onSubmit={handleSubmit}>
        <Row>
          <Col md={6}>
            <Form.Group>
              <Form.Label>Email</Form.Label>
              <Form.Control type="email" name="email" onChange={handleChange} required />
              {errors.email && <span className="text-danger">{errors.email}</span>}
            </Form.Group>

            <Form.Group>
              <Form.Label>Password</Form.Label>
              <Form.Control type="password" name="password" onChange={handleChange} required />
              {errors.password && <span className="text-danger">{errors.password}</span>}
            </Form.Group>

            <Form.Group>
              <Form.Label>Repeat Password</Form.Label>
              <Form.Control type="password" name="repeatPassword" onChange={handleChange} required />
              {errors.repeatPassword && <span className="text-danger">{errors.repeatPassword}</span>}
            </Form.Group>

            <Form.Group>
              <Form.Label>Phone</Form.Label>
              <Form.Control type="text" name="phone" onChange={handleChange} required />
              {errors.phone && <span className="text-danger">{errors.phone}</span>}
            </Form.Group>
          </Col>

          <Col md={6}>
            <Form.Group>
              <Form.Label>First Name</Form.Label>
              <Form.Control type="text" name="firstName" onChange={handleChange} required />
            </Form.Group>

            <Form.Group>
              <Form.Label>Last Name</Form.Label>
              <Form.Control type="text" name="lastName" onChange={handleChange} required />
            </Form.Group>

            <Form.Group>
              <Form.Label>Address</Form.Label>
              <Form.Control type="text" name="address" onChange={handleChange} required />
            </Form.Group>

            <Form.Group>
              <Form.Label>Country</Form.Label>
              <Form.Control type="text" name="country" onChange={handleChange} required />
            </Form.Group>
          </Col>
        </Row>

        <Button variant="primary" type="submit" className="mt-3">Register</Button>
      </Form>
    </Container>
  );
};

export default RegistrationForm;
