library(shiny)

shinyServer(
  function(input, output) {

    # Tutorial 09
    # Chagne num_col to a interactive function.
    num_col <- reactive({
      as.numeric(input$var)
    })

    # To use num_col, treat as a function.
    output$var <- renderText(paste("Data set variable/column name is ",
                                   names(iris[num_col()])))

    output$bins <- renderText(paste("Number of historgram BINs is ",
                                     input$bins))

    output$color <- renderText(paste("Color of histogram is ",
                                     input$color))

    output$my_hist <- renderPlot({
      # The parater name for color is "col".
      hist(iris[, num_col()],
           breaks = seq(min(iris[, num_col()]),
                        max(iris[, num_col()]),
                        l = input$bins + 1),
           col = input$color,
           main = "Historgram of iris dataset",
           xlab = names(iris[num_col()]))
    })

    # Tutorial 10
    # downloadHandler is connected to downloadButton.
    output$down <- downloadHandler(
      filename = function() {
        paste("iris", input$download_type, sep = ".")
      },

      content = function(file) {
        # open the device
        if (input$download_type == "png")
          png(file)
        else
          pdf(file)

        # create the plot
        hist(iris[, num_col()],
             breaks = seq(min(iris[, num_col()]),
                          max(iris[, num_col()]),
                          l = input$bins + 1),
             col = input$color,
             main = "Historgram of iris dataset",
             xlab = names(iris[num_col()]))

        # close the device
        dev.off()
      }
    )
  }
)
