import { render, screen } from "@testing-library/react";
import React from "react";
import { CreateState } from "./CreateState";

describe("CreateState component", () => {
  it("should render", () => {
    render(<CreateState />);

    const taxAmountInput = screen.getByLabelText(/tax amount/i);
    const stateNameInput = screen.getByLabelText(/state name/i);

    expect(taxAmountInput).toBeInTheDocument();
    expect(stateNameInput).toBeInTheDocument();
  });
});
