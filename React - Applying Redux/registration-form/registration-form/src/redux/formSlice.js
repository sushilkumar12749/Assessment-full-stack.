import { createSlice } from "@reduxjs/toolkit";

const initialState = {
  formData: {},
};

const formSlice = createSlice({
  name: "form",
  initialState,
  reducers: {
    setFormData: (state, action) => {
      state.formData = action.payload;
    },
  },
});

export const { setFormData } = formSlice.actions;
export default formSlice.reducer;
