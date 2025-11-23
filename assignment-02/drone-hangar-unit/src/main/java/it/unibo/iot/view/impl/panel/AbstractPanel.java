package it.unibo.iot.view.impl.panel;

import java.awt.FlowLayout;
import java.io.Serial;
import java.util.Objects;

import javax.swing.BorderFactory;
import javax.swing.JPanel;

import it.unibo.iot.controller.api.Controller;
import it.unibo.iot.view.api.panel.Panel;

/**
 * An abstract base class for panel implementations that provides common
 * functionality and enforces the {@link Panel} interface contract.
 * 
 * <p>
 * This class extends {@link JPanel} and implements {@link Panel}, serving
 * as a foundation for concrete panel implementations. It provides a consistent
 * visual style with standardized layout and borders and manages a reference
 * to the application controller for data access and business logic operations.
 * </p>
 * 
 * @author Alessandro Rebosio
 * @see Panel
 * @see JPanel
 * @see Controller
 * @since 1.0
 */
public abstract class AbstractPanel extends JPanel implements Panel {

    private static final int GAPS = 10;

    @Serial
    private static final long serialVersionUID = 1L;
    private final transient Controller ctrl;

    /**
     * Constructs a new AbstractPanel with a standardized configuration, a
     * reference to the application controller and a custom title used for the
     * panel border. This constructor is safe because it does not invoke any
     * overridable methods during construction.
     *
     * @param controller the application controller, cannot be null
     * @param title      the title to use for the panel border, cannot be null
     */
    public AbstractPanel(final Controller controller, final String title) {
        this.ctrl = Objects.requireNonNull(controller, "The controller cannot be null.");

        super.setLayout(new FlowLayout(FlowLayout.LEFT, GAPS, GAPS));
        super.setBorder(BorderFactory.createTitledBorder(Objects.requireNonNull(title, "The title cannot be null.")));
    }

    /**
     * Updates the panel state and refreshes its contents by delegating
     * to the abstract {@link #update(Controller)} method with the current
     * controller.
     */
    @Override
    public void update() {
        this.update(this.ctrl);
    }

    /**
     * Updates the panel state and refreshes its contents using the provided
     * controller.
     * Concrete implementations must override this method to define how the panel
     * updates its visual representation based on the current state of the
     * application.
     *
     * @param controller the controller to use for accessing application state and
     *                   logic
     */
    protected abstract void update(Controller controller);

}
