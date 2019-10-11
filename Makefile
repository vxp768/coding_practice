.PHONY: clean All

All:
	@echo "----------Building project:[ sliding_window - Debug ]----------"
	@cd "sliding_window" && "$(MAKE)" -f  "sliding_window.mk"
clean:
	@echo "----------Cleaning project:[ sliding_window - Debug ]----------"
	@cd "sliding_window" && "$(MAKE)" -f  "sliding_window.mk" clean
